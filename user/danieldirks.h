#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FN,
};

enum unicode_names {
    UMLA,
    UMLAA,
    UMLO,
    UMLOO,
    UMLU,
    UMLUU,
    UMLS,
    UMLSS,
    EURO,
};

// custom keys
#define DE_UMLA UP(UMLA, UMLAA)
#define DE_UMLO UP(UMLO, UMLOO)
#define DE_UMLU UP(UMLU, UMLUU)
#define DE_UMLS UP(UMLS, UMLSS)
#define DE_EURO UM(EURO)
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define DD_CAPS LT(_FN, KC_CAPS)
#define KC_ZOUT LCTL(KC_MINS)
#define KC_ZOIN LCTL(KC_EQL)
#define KC_ZRST LCTL(KC_0)
