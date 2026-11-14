# The board package `proffie firmware build` was last verified against.
export const core = {
    id: 'proffieboard:stm32l4'
    version: '4.6'
    url: 'https://profezzorn.github.io/arduino-proffieboard/package_proffieboard_index.json'
}

# Board menu options go into the FQBN. `opt: os` is Smallest Code.
# proffieboard_v2_config.h requires dosfs=sdspi.
# proffieboard_v3_config.h requires dosfs=sdmmc1, SDIO High Speed.
export const boards = {
    v2: {
        fqbn: 'proffieboard:stm32l4:ProffieboardV2-L433CC'
        options: {usb: cdc_msc_webusb, dosfs: sdspi, opt: os}
    }
    v3: {
        fqbn: 'proffieboard:stm32l4:ProffieboardV3-L452RE'
        options: {usb: cdc_msc_webusb, dosfs: sdmmc1, opt: os}
    }
}

export const sabers = [
    [id name board config];
    [exile 'Korbanth Exile' v2 config/hazel_exile.h]
    [count_dooku 'Dooku V3' v3 config/hazel_count_dooku.h]
    [graflex_anh 'Graflex ANH' v3 config/hazel_graflex_anh.h]
    [vader_rogue_one 'Vader MPP R1' v3 config/hazel_vader_rogue_one.h]
]
