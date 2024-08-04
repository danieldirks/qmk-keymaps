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
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_BREATHING);
}

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
