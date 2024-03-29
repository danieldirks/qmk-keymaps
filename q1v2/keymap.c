#include "danieldirks.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* _BASE default
     * +---------------------------------------------------------------------------------------------+
     * | Esc |  F1  | F2  | F3  | F4  |  F5  | F6  | F7  | F8  |  F9  | F10 | F11 | F12 |  Del | VOL |
     * |---------------------------------------------------------------------------------------------|
     * | ~ ` |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Bspc    | Lok |
     * |---------------------------------------------------------------------------------------------|
     * | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  \    | Prt |
     * |---------------------------------------------------------------------------------------------|
     * | Caps   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |  Enter     | Scr |
     * |---------------------------------------------------------------------------------------------|
     * | Shift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift    | Up  |     |
     * |---------------------------------------------------------------------------------------------|
     * | Ctl  | Mod  | Alt  |               Space               | Alt | Fn  | Ctl  | Lft | Dwn | Rgt |
     * +---------------------------------------------------------------------------------------------+
     */
    [_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            QK_LOCK,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PSCR,
        MO(_FN),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_SCRL,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(_FN),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),


    /* _FN
     * +---------------------------------------------------------------------------------------------+
     * | BOOT| BRID | BRIU| TASK| FILE|  VAD | VAU | MPRV| MPLY|  MNXT| MUTE| VOLD| VOLU|   -  | RGB |
     * |---------------------------------------------------------------------------------------------|
     * |  -  |  -  |  -  |  -  |  -  |  -  |  -  |  -  |  -  |  -  |  -  |  ß  |  -  |  -      | LOCK|
     * |---------------------------------------------------------------------------------------------|
     * | RGB   |  -  |  -  |  €  |  -  |  -  |  -  |  -  |  -  |  -  |  -  |  Ü  |  -  |  -    |  -  |
     * |---------------------------------------------------------------------------------------------|
     * |  -     |  -  |  -  |  -  |  -  |  -  | C-H | C-J | C-K | C-L |  Ö  |  Ä  |  -         |  -  |
     * |---------------------------------------------------------------------------------------------|
     * | Shift    |  -  |  -  |  -  |  -  |  -  |  -  |  -  |  -  |  -  |  -  | Shift    | PU  |     |
     * |---------------------------------------------------------------------------------------------|
     * |  -   |  -   |  -   |               C-Space             |  -  |  -  |  -   | Hom | PD  | End |
     * +---------------------------------------------------------------------------------------------+
     */
    [_FN] = LAYOUT_ansi_82(
        QK_BOOT,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,     KC_MPRV,     KC_MPLY,     KC_MNXT,     KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            KC_ZRST,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,     _______,     _______,     _______,  DE_UMLS,  _______,  _______,            KC_SLEP,
        RGB_MOD,  _______,  _______,  DE_EURO,  _______,  _______,  _______,     _______,     _______,     _______,     _______,  DE_UMLU,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  LCTL(KC_H),  LCTL(KC_J),  LCTL(KC_K),  LCTL(KC_L),  DE_UMLO,  DE_UMLA,            _______,            _______,
        KC_LSFT,            _______,  _______,  _______,  _______,  _______,     _______,     _______,     _______,     _______,  _______,            KC_RSFT,  KC_PGUP,
        _______,  _______,  _______,                                LCTL(KC_SPC),                                       _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_END),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN]   = { ENCODER_CCW_CW(KC_ZOUT, KC_ZOIN)},
};
#endif // ENCODER_MAP_ENABLE
