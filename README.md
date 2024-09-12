# QMK Keymaps

Configuration for my QMK custom keyboards.

## Keyboards

* [Keychron Q1 Version 2 ANSI](./q1v2/)
* [Keychron Q0 Plus](./q0/)

## Usage

### Setup

**Requirements:** [qmk](https://docs.qmk.fm/#/newbs_getting_started?id=set-up-your-environment) and [make](https://www.gnu.org/software/make/). I use [WinCompose](https://github.com/samhocevar/wincompose) for German unicode characters.

```shell
git clone https://github.com/danieldirks/qmk-keymaps.git
cd qmk-keymaps

make setup
```

### Build

```shell
make <keyboard>
```

### Flash

Set keyboard to bootloader mode and run build with `$FLASH` set to a non-empty string, e.g.

```shell
make <keyboard> FLASH=yes
```

On Windows, use [QMK Toolbox](https://github.com/qmk/qmk_toolbox) to flash
`build/<keyboard_name>_<keymap_name>.bin` onto the corresponding board.
