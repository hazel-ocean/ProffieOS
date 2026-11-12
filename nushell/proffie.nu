# Build and flash Hazel's sabers.

use sabers.nu [core boards sabers]

const repo = path self ..

def saber-ids [] {
    $sabers | each {|s| {value: $s.id, description: $s.name} }
}

def resolve [id: string, span: record]: nothing -> record {
    let matches = $sabers | where id == $id
    if ($matches | is-empty) {
        error make {
            msg: $'Unknown saber: ($id)'
            label: {text: 'run `proffie` for the list', span: $span}
        }
    }
    $matches | first
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

# Compile a saber's firmware into build/<id>/.
export def build [
    id: string@saber-ids  # The saber to build
    --usb: string  # Board menu `usb`; defaults per board
    --dosfs: string  # Board menu `dosfs`; defaults per board
    --opt: string  # Board menu `opt`; defaults per board
]: nothing -> nothing {
    let saber = resolve $id (metadata $id).span
    require-core
    let out = $repo | path join build $id

    # arduino-cli splits the compile recipe with shell quoting. The single
    # quotes keep the double quotes, so CONFIG_FILE stays a string literal.
    # build.extra_flags is not free: the board uses it for its own flags.
    let define = $"compiler.cpp.extra_flags='-DCONFIG_FILE=\"($saber.config)\"'"

    (arduino compile
        --fqbn (fqbn $saber.board {usb: $usb, dosfs: $dosfs, opt: $opt})
        --build-property $define
        --build-path ($out | path join work)
        --output-dir $out
        $repo)
}

# Compile a saber and flash it over USB.
export def upload [
    id: string@saber-ids  # The saber to flash
    --port (-p): string  # Serial port; see `proffie ports`
    --usb: string  # Board menu `usb`; defaults per board
    --dosfs: string  # Board menu `dosfs`; defaults per board
    --opt: string  # Board menu `opt`; defaults per board
]: nothing -> nothing {
    let saber = resolve $id (metadata $id).span
    let port = $port | default { detect-port }
    build $id --usb $usb --dosfs $dosfs --opt $opt

    (arduino upload
        --fqbn (fqbn $saber.board {usb: $usb, dosfs: $dosfs, opt: $opt})
        --input-dir ($repo | path join build $id)
        --port $port
        $repo)
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
export def sync-fonts [
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
