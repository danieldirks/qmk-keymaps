RGB_MATRIX_EFFECT(BREATHING)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool BREATHING(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // init on first run: if (params->init)

    // change slowly between blue and magenta
    uint8_t delta    = 30;
    HSV      hsv     = rgb_matrix_config.hsv;
    uint16_t time    = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 64);
    hsv.h            = hsv.h + 170 + scale8(abs8(sin8(time) - 128) * 2, delta);
    RGB rgb          = hsv_to_rgb(hsv);

    // update matrix
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
