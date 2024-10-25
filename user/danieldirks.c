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

#if defined(RGB_MATRIX_ENABLED) && defined(RGB_MATRIX_CUSTOM_USER)
void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_BREATHING);
}
#endif

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_LINUX:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;
        case OS_MACOS:
            set_unicode_input_mode(UNICODE_MODE_MACOS);
            break;
        case OS_WINDOWS:
            set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
            break;
        case OS_IOS:
        case OS_UNSURE:
            break;
    }
    return true;
}
