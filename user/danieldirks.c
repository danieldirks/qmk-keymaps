#include "danieldirks.h"

const uint32_t unicode_map[] PROGMEM = {
    [UMLA]  = 0x00E4,
    [UMLAA] = 0x00C4,
    [UMLO]  = 0x00F6,
    [UMLOO] = 0x00D6,
    [UMLU]  = 0x00FC,
    [UMLUU] = 0x00DC,
    [UMLS]  = 0x00DF,
    [UMLSS] = 0x1E9E,
    [EURO]  = 0x20AC,
};

void keyboard_post_init_user(void) {
    // rgb setup https://docs.qmk.fm/#/feature_rgb_matrix?id=functions
    rgb_matrix_sethsv_noeeprom(0, 0, 0);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_enable_noeeprom();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    switch (get_highest_layer(state)) {
        case _FN:
            rgb_matrix_sethsv_noeeprom(HSV_WHITE);
            break;
        default:
            rgb_matrix_sethsv_noeeprom(0, 0, 0);
            break;
    }
    return state;
}
