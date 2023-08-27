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
#define DE_UMLA XP(UMLA, UMLAA)
#define DE_UMLO XP(UMLO, UMLOO)
#define DE_UMLU XP(UMLU, UMLUU)
#define DE_UMLS XP(UMLS, UMLSS)
#define DE_EURO X(EURO)
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define DD_CAPS LT(_FN, KC_CAPS)
