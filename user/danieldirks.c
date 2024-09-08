#include "danieldirks.h"

const uint32_t unicode_map[] PROGMEM = {
    [UMLA]  = 0xE4,
    [UMLAA] = 0xC4,
    [UMLO]  = 0xF6,
    [UMLOO] = 0xD6,
    [UMLU]  = 0xFC,
    [UMLUU] = 0xDC,
    [UMLS]  = 0xDF,
    [UMLSS] = 0x1E9E,
    [EURO]  = 0x20AC,
};

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_BREATHING);
}
