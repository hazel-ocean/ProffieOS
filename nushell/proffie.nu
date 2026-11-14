# Build and flash Hazel's sabers.

use sabers.nu [core boards sabers]

const repo = path self ..

def saber-ids [] {
    $sabers | each {|s| {value: $s.id, description: $s.name} }
}

def resolve [id: string, span?: record]: nothing -> record {
    let matches = $sabers | where id == $id
    if ($matches | is-empty) {
        let msg = $'Unknown saber: ($id)'
        if $span == null {
            error make --unspanned {msg: $msg, help: 'Run `proffie` for the list.'}
        }
        error make {
            msg: $msg
            label: {text: 'run `proffie` for the list', span: $span}
        }
    }
    $matches | first
}

# The saber named by the positional id, else by the pipeline input: an id,
# or a record from `proffie info` or `proffie build`.
def target [id: any, input: any]: nothing -> record {
    if $id != null {
        return (resolve $id (metadata $id).span)
    }
    let key = match ($input | describe | str replace --regex '<.*' '') {
        record => $input.id?
        string => $input
        _ => null
    }
    if $key == null {
        error make --unspanned {
            msg: 'No saber given'
            help: 'Pass an id, or pipe in `proffie info <id>`.'
        }
    }
    resolve $key
}

def out-dir [id: string]: nothing -> path {
    $repo | path join build $id
}

# Flags override the board's default menu options.
def fqbn [board: string, overrides: record]: nothing -> string {
    let spec = $boards | get $board
    let options = (
        $spec.options
        | merge ($overrides | compact)
        | items {|k, v| $'($k)=($v)' }
        | str join ','
    )
    $'($spec.fqbn):($options)'
}

# Uses nix when arduino-cli is not on PATH.
def --wrapped arduino [...args] {
    if (which arduino-cli | is-not-empty) {
        ^arduino-cli ...$args
    } else if (which nix | is-not-empty) {
        ^nix shell nixpkgs#arduino-cli -c arduino-cli ...$args
    } else {
        error make --unspanned {
            msg: 'arduino-cli not found'
            help: 'Install arduino-cli (https://arduino.github.io/arduino-cli/) or nix.'
        }
    }
}

def require-core []: nothing -> nothing {
    let installed = (arduino core list --json
        | from json
        | get platforms
        | where id == $core.id)
    if ($installed | is-empty) {
        error make --unspanned {
            msg: $'Board package ($core.id) is not installed'
            help: 'Run `proffie setup` first.'
        }
    }
}

# Install the Proffieboard board package.
#
# Run once per machine before `proffie build`. Reinstalling the same
# version does nothing.
export def setup [
    --version: string  # Board package version; defaults to the verified one
]: nothing -> nothing {
    let version = $version | default $core.version
    arduino core update-index --additional-urls $core.url
    (arduino core install $'($core.id)@($version)'
        --additional-urls $core.url)
}

# List the sabers.
export def main []: nothing -> table {
    $sabers
}

# Show one saber: its registry row, default FQBN and build folder.
#
# Pipe it into `proffie build` or `proffie upload`.
export def info [
    id: string@saber-ids  # The saber to show
]: nothing -> record {
    let saber = resolve $id (metadata $id).span
    $saber | merge {
        fqbn: (fqbn $saber.board {})
        out_dir: (out-dir $saber.id)
    }
}

# Compile a saber's firmware into build/<id>/.
#
# Takes the saber as an id, or from the pipeline. Outputs the saber with
# the FQBN used and the firmware path, for `proffie upload`.
export def build [
    id?: string@saber-ids  # The saber to build; else the pipeline input
    --usb: string  # Board menu `usb`; defaults per board
    --dosfs: string  # Board menu `dosfs`; defaults per board
    --opt: string  # Board menu `opt`; defaults per board
]: [nothing -> record, string -> record, record -> record] {
    let saber = target $id $in
    require-core
    let out = out-dir $saber.id
    let board_fqbn = fqbn $saber.board {usb: $usb, dosfs: $dosfs, opt: $opt}

    # arduino-cli splits the compile recipe with shell quoting. The single
    # quotes keep the double quotes, so CONFIG_FILE stays a string literal.
    # build.extra_flags is not free: the board uses it for its own flags.
    let define = $"compiler.cpp.extra_flags='-DCONFIG_FILE=\"($saber.config)\"'"

    (arduino compile
        --fqbn $board_fqbn
        --build-property $define
        --build-path ($out | path join work)
        --output-dir $out
        $repo)

    $saber | merge {
        fqbn: $board_fqbn
        out_dir: $out
        firmware: ($out | path join ProffieOS.ino.dfu)
    }
}

# Flash a saber over USB, compiling it first unless the input is a build.
#
# Takes the saber as an id, or from the pipeline. Input from
# `proffie build` is flashed as built.
export def upload [
    id?: string@saber-ids  # The saber to flash; else the pipeline input
    --port (-p): string  # Serial port; see `proffie ports`
    --usb: string  # Board menu `usb`; defaults per board
    --dosfs: string  # Board menu `dosfs`; defaults per board
    --opt: string  # Board menu `opt`; defaults per board
]: [nothing -> record, string -> record, record -> record] {
    let input = $in
    let saber = target $id $input
    let flags = {usb: $usb, dosfs: $dosfs, opt: $opt} | compact
    let given_build = (
        $id == null
        and ($input | describe | str starts-with record)
        and ($input.firmware? != null)
    )
    if $given_build and ($flags | is-not-empty) {
        error make --unspanned {
            msg: 'Board menu flags conflict with a piped build'
            help: 'Pass the flags to `proffie build` instead.'
        }
    }
    if $given_build and not ($input.firmware | path exists) {
        error make --unspanned {msg: $'No firmware at ($input.firmware)'}
    }
    let port = $port | default { detect-port }
    let built = if $given_build {
        $input
    } else {
        $saber | build --usb $usb --dosfs $dosfs --opt $opt
    }

    (arduino upload
        --fqbn $built.fqbn
        --input-dir $built.out_dir
        --port $port
        $repo)
    $built | merge {port: $port}
}

# The address of each serial port that matches a Proffieboard.
def proffie-ports []: record -> list<string> {
    $in
    | get -o detected_ports
    | default []
    | where {|p|
        $p.matching_boards?
        | default []
        | any {|b| $b.fqbn | str starts-with $'($core.id):' }
    }
    | get port.address
}

# Without a port, the 1200 bps touch that enters DFU does not run, and
# stm32l4-upload times out.
def detect-port []: nothing -> string {
    let found = arduino board list --json | from json | proffie-ports
    match ($found | length) {
        1 => ($found | first)
        0 => {
            error make --unspanned {
                msg: 'No Proffieboard found'
                help: 'Connect the board, or pass --port. See `proffie ports`.'
            }
        }
        _ => {
            error make --unspanned {
                msg: $'More than one Proffieboard found: ($found | str join ", ")'
                help: 'Pass --port to choose one.'
            }
        }
    }
}

# List connected boards.
export def ports []: nothing -> any {
    arduino board list
}

def --wrapped repo-git [...args] {
    ^git -C $repo ...$args
}

# Fast-forward master to upstream, push it to the fork, and list releases.
#
# Fetches upstream's branches and tags. Fast-forwards local master to
# upstream/master and refuses anything else. Pushes master and tags to
# origin. hazels-sabers is untouched: it moves by rebase onto a release
# tag. Lists release tags newer than its base. `behind` counts the commits
# the fork's master lacked before the sync. The push sends them, unless
# --no-push.
export def "upstream sync" [
    --no-push  # Update local refs only
]: nothing -> record {
    repo-git fetch upstream --tags --prune
    let before = repo-git rev-parse --short master | str trim
    let current = repo-git rev-parse --abbrev-ref HEAD | str trim
    # A refspec cannot update the checked-out branch.
    if $current == 'master' {
        repo-git merge --ff-only upstream/master
    } else {
        repo-git fetch . upstream/master:master
    }
    let after = repo-git rev-parse --short master | str trim
    repo-git fetch --quiet origin master
    let ahead = repo-git rev-list --count origin/master..master | str trim | into int
    if not $no_push {
        repo-git push origin master --tags
    }

    let base = (
        repo-git describe --tags --abbrev=0 --match 'v*'
            (repo-git merge-base hazels-sabers upstream/master | str trim)
        | str trim
    )
    {
        master: (if $before == $after { $after } else { $'($before)..($after)' })
        behind: $ahead
        base: $base
        newer_releases: (
            repo-git tag --list 'v*' --sort=-v:refname --contains $base
            | lines
            | where $it != $base
        )
    }
}

const library = path self '../../Sound Fonts/Library'

# The font folders and tracks that a saber's presets name.
def preset-assets [config: path]: nothing -> record {
    # A commented-out preset is not on the card.
    let entries = (
        open --raw $config
        | str replace --all --regex '(?s)/\*.*?\*/' ''
        | str replace --all --regex '//[^\n]*' ''
        | parse --regex '\{\s*"(?<fonts>[^"]*)"\s*,\s*"(?<track>[^"]*)"'
    )
    {
        fonts: (
            $entries.fonts
            | each { split row ';' }
            | flatten
            | where $it != ''
            | uniq
        )
        tracks: ($entries.track | where $it != '' | uniq)
    }
}

# Copy the fonts and tracks a saber's presets name to its SD card.
#
# Sources are in `Sound Fonts/Library`, beside the repo. Each synced font
# folder becomes an exact copy: files the library lacks are deleted from
# it. Everything else on the card stays. Lists what the library lacks.
export def "fonts sync" [
    id: string@saber-ids  # The saber whose presets to read
    card: path  # The mounted SD card, e.g. /Volumes/SABER
    --dry-run (-n)  # Show what would be copied and deleted
]: nothing -> table {
    let saber = resolve $id (metadata $id).span
    if not ($card | path exists) {
        error make {
            msg: $'No such directory: ($card)'
            label: {text: 'mount the SD card first', span: (metadata $card).span}
        }
    }
    let assets = preset-assets ($repo | path join $saber.config)
    let items = (
        ($assets.fonts | each {|f| {kind: font, name: $f, dir: true} })
        ++ ($assets.tracks | each {|t| {kind: track, name: $t, dir: false} })
    )
    # --delete must never reach above the folder a preset names.
    let unsafe = $items | where {|i|
        ($i.name | str starts-with '/') or ('..' in ($i.name | path split))
    }
    if ($unsafe | is-not-empty) {
        error make --unspanned {
            msg: $'Unsafe preset paths: ($unsafe.name | str join ", ")'
        }
    }
    # FAT keeps mtimes to 2 s, and stores no owner or mode.
    let rsync_args = [
        --recursive
        --times
        --modify-window=1
        --exclude=.DS_Store
        --itemize-changes
        --mkpath
        ...(if $dry_run { [--dry-run] } else { [] })
    ]

    $items | each {|item|
        let src = $library | path join $item.name
        let dest = $card | path join $item.name
        if not ($src | path exists) {
            return {
                kind: $item.kind
                name: $item.name
                status: missing
                copied: 0
                deleted: 0
            }
        }
        let result = if $item.dir {
            ^rsync ...$rsync_args --delete $'($src)/' $dest | complete
        } else {
            ^rsync ...$rsync_args $src $dest | complete
        }
        if $result.exit_code != 0 {
            error make --unspanned {
                msg: $'rsync failed for ($item.name)'
                help: ($result.stderr | str trim)
            }
        }
        let changes = $result.stdout | lines
        {
            kind: $item.kind
            name: $item.name
            status: (if $dry_run { 'would sync' } else { 'synced' })
            copied: ($changes | where ($it | str starts-with '>f') | length)
            deleted: ($changes | where ($it | str starts-with '*deleting') | length)
        }
    }
}
