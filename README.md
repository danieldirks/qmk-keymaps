# QMK Keymaps

Configuration for my QMK custom keyboards.

> [!NOTE]
> This branch is based on [Keychron's bluetooth_playground](https://github.com/Keychron/qmk_firmware/tree/bluetooth_playground).
> Refer to `main` for my native QMK keyboards.

## Keyboards

* [Keychron K7 Pro ANSI](./k7_pro/)

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
