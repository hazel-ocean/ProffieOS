# Hazel's Sabers (ProffieOS fork)

- Branch `hazels-sabers` tracks upstream ProffieOS. Base: tag `v8.10`.
- Remote `upstream` is `profezzorn/ProffieOS`. There is no fork remote yet.
- Customizations are additive. Edit an upstream file only when a saber
  needs it, and say so in the commit message.

## Building

- `overlay use .` from the repo root loads `mod.nu`, which loads
  `nushell/`.
- `saber` lists the sabers.
- `saber build <id>` compiles into `build/<id>/`.
- `saber upload <id>` compiles and flashes.
- `nushell/saber.nu` passes `CONFIG_FILE` as a compiler define. Leave
  the `CONFIG_FILE` lines in `ProffieOS.ino` commented out.
- The registry of sabers is the `sabers` const in `nushell/sabers.nu`.

## Sabers

| Saber          | Board | Prop    | Status                          |
|----------------|-------|---------|---------------------------------|
| Korbanth Exile | V2    | fett263 | 8.10, `config/hazel_exile.h`    |
| Dooku V3       | V3    | fett263 | 7.12, not ported                |
| Graflex ANH    | V3    | sa22c   | 7.12, not ported                |
| Vader MPP R1   | V3    | fett263 | 7.12, not ported                |

- Config files are `config/hazel_<id>.h`. They must stay directly in
  `config/`, because they include `proffieboard_*.h` and `../props/...`
  by relative path.
- Exile uses 97% of the V2's flash. Check the size after each change.

## Porting to 8.10

- The 7.12 sources are in `../My Lightsabers/<saber>/`. They are
  read-only reference.
- Port one saber per commit. Add it to `nushell/sabers.nu`.
- Run `saber build <id>` before committing.
- Reference material: `../CCSabers Support/` (vendor configs for 7.12),
  `../Blade Styles/`.
- Sound fonts and style libraries stay outside the repo.
