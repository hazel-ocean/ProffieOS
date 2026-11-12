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
    build $id --usb $usb --dosfs $dosfs --opt $opt

    let port_args = if $port == null { [] } else { [--port $port] }
    (arduino upload
        --fqbn (fqbn $saber.board {usb: $usb, dosfs: $dosfs, opt: $opt})
        --input-dir ($repo | path join build $id)
        ...$port_args
        $repo)
}

# List connected boards.
export def ports []: nothing -> any {
    arduino board list
}
