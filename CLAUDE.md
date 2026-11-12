# Hazel's Sabers (ProffieOS fork)

- Branch `hazels-sabers` tracks upstream ProffieOS. Base: tag `v8.10`.
- Remote `upstream` is `profezzorn/ProffieOS`. There is no fork remote yet.
- Customizations are additive. Edit an upstream file only when a saber
  needs it, and say so in the commit message.

## Building

- `overlay use . as proffie` from the repo root loads `mod.nu`, which loads
  `nushell/`.
- `.env.nu` returns `{overlays: [mod.nu]}`, so a shell with the nuenv hook
  loads the commands on entering the repo. Run `nuenv allow` once.
- `proffie setup` installs the Proffieboard board package. Run it once
  per machine. It needs `arduino-cli` or nix on the PATH.
- `proffie` lists the sabers.
- `proffie build <id>` compiles into `build/<id>/`.
- `proffie upload <id>` compiles and flashes.
- `proffie sync-fonts <id> <card>` copies the fonts and tracks that the
  saber's presets name from `../Sound Fonts/Library` to a mounted SD card.
  Each synced font folder becomes an exact copy of the library's, so files
  in it that the library lacks are deleted. Other files on the card stay.
  It lists each font or track that the library lacks. Preview with `-n`.
- `nushell/proffie.nu` passes `CONFIG_FILE` as a compiler define. Leave
  the `CONFIG_FILE` lines in `ProffieOS.ino` commented out.
- The registry of sabers is the `sabers` const in `nushell/sabers.nu`.
- The `core` const in `nushell/sabers.nu` pins the board package
  version. Raise it only after `proffie build` passes for every saber.

## Sabers

| Saber          | Board | Prop    | Status                          |
|----------------|-------|---------|---------------------------------|
| Korbanth Exile | V2    | fett263 | 8.10, `config/hazel_exile.h`    |
| Dooku V3       | V3    | fett263 | 8.10, `config/hazel_count_dooku.h` |
| Graflex ANH    | V3    | sa22c   | 8.10, `config/hazel_graflex_anh.h` |
| Vader MPP R1   | V3    | fett263 | 8.10, `config/hazel_vader_rogue_one.h` |

- Config files are `config/hazel_<id>.h`. They must stay directly in
  `config/`, because they include `proffieboard_*.h` and `../props/...`
  by relative path.
- Exile uses 97% of the V2's flash. Check the size after each change.

## Porting to 8.10

- The 7.12 sources are in `../My Lightsabers/<saber>/`. They are
  read-only reference.
- Port one saber per commit. Add it to `nushell/sabers.nu`.
- Run `proffie build <id>` before committing.
- Reference material: `../CCSabers Support/` (vendor configs for 7.12),
  `../Blade Styles/`.
- Sound fonts and style libraries stay outside the repo.
