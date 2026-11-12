# Build and flash Hazel's sabers.
#
# Load with `use saber.nu`, then run `saber` to list the sabers.

const repo = path self .

const boards = {
    v2: 'proffieboard:stm32l4:ProffieboardV2-L433CC'
    v3: 'proffieboard:stm32l4:ProffieboardV3-L452RE'
}

const sabers = [
    [id name board config];
    [exile 'Korbanth Exile' v2 config/hazel_exile.h]
]

def saber-ids [] {
    $sabers | each {|s| {value: $s.id, description: $s.name} }
}

def resolve [id: string, span: record]: nothing -> record {
    let matches = $sabers | where id == $id
    if ($matches | is-empty) {
        error make {
            msg: $'Unknown saber: ($id)'
            label: {text: 'run `saber` for the list', span: $span}
        }
    }
    $matches | first
}

def fqbn [board: string, usb: string, opt: string]: nothing -> string {
    $'($boards | get $board):usb=($usb),opt=($opt)'
}

# Uses nix when arduino-cli is not on PATH.
def --wrapped arduino [...args] {
    if (which arduino-cli | is-not-empty) {
        ^arduino-cli ...$args
    } else {
        ^nix shell nixpkgs#arduino-cli -c arduino-cli ...$args
    }
}

# List the sabers.
export def main []: nothing -> table {
    $sabers
}

# Compile a saber's firmware into build/<id>/.
export def build [
    id: string@saber-ids  # The saber to build
    --usb: string = 'cdc_msc_webusb'  # Board menu `usb`
    --opt: string = 'os'  # Board menu `opt`
]: nothing -> nothing {
    let saber = resolve $id (metadata $id).span
    let out = $repo | path join build $id

    # arduino-cli splits the compile recipe with shell quoting. The single
    # quotes keep the double quotes, so CONFIG_FILE stays a string literal.
    # build.extra_flags is not free: the board uses it for its own flags.
    let define = $"compiler.cpp.extra_flags='-DCONFIG_FILE=\"($saber.config)\"'"

    (arduino compile
        --fqbn (fqbn $saber.board $usb $opt)
        --build-property $define
        --build-path ($out | path join work)
        --output-dir $out
        $repo)
}

# Compile a saber and flash it over USB.
export def upload [
    id: string@saber-ids  # The saber to flash
    --port (-p): string  # Serial port; see `saber ports`
    --usb: string = 'cdc_msc_webusb'  # Board menu `usb`
    --opt: string = 'os'  # Board menu `opt`
]: nothing -> nothing {
    let saber = resolve $id (metadata $id).span
    build $id --usb $usb --opt $opt

    let port_args = if $port == null { [] } else { [--port $port] }
    (arduino upload
        --fqbn (fqbn $saber.board $usb $opt)
        --input-dir ($repo | path join build $id)
        ...$port_args
        $repo)
}

# List connected boards.
export def ports []: nothing -> any {
    arduino board list
}
