#include QMK_KEYBOARD_H

// Features
#include "features/repeat_key.h"
#include "features/oneshot.h"
#include "features/custom_shift_keys.h"

enum layers {
    // Base layers
    _QWERTY = 0,
    _SOUL,
    _UN,
    _UN_EXTRA,
    // Right hand layers
    _NAV,
    _FUNC,
    _MISC,
    // Left hand layers
    _EXPR
};

enum custom_keycodes {
    // Repeat and reverse repeat keys
    REPEAT = SAFE_RANGE,
    ALTREP,
    // One shot layers because OSL is broken rn
    OS_NAV,
    OS_FUNC,
    OS_MISC,
    OS_EXPR
};

#define DF_SOUL DF(_SOUL)
#define DF_QWER DF(_QWERTY)
#define DF_UKR DF(_UN)

#define OS_SFT OSM(MOD_LSFT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)

// **************************************************
combo_t key_combos[] = {};
uint16_t COMBO_LEN = 0;

// **************************************************

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                          KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                          KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_QUES , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,OS_NAV  ,KC_SPC  ,                          OS_SFT  ,OS_EXPR ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_SOUL] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       KC_Q    ,KC_W    ,KC_L    ,KC_D    ,KC_P    ,                          KC_K    ,KC_M    ,KC_U    ,KC_Y    ,KC_QUOT ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_A    ,KC_S    ,KC_R    ,KC_T    ,KC_G    ,                          KC_F    ,KC_N    ,KC_E    ,KC_I    ,KC_O    , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_J    ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,                          KC_B    ,KC_H    ,REPEAT  ,KC_DOT  ,KC_COMM , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,OS_NAV  ,KC_SPC  ,                          OS_SFT  ,OS_EXPR ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_UN] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                          KC_Y    ,KC_U    ,KC_I    ,KC_P    ,KC_LBRC ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                          KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_QUES , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,OS_NAV  ,KC_SPC  ,                          OS_SFT  ,OS_EXPR ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_UN_EXTRA] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,_______ ,_______ ,                          _______ ,_______ ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_NAV] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                          KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       OS_GUI  ,OS_ALT  ,OS_CTL  ,OS_SFT  ,_______ ,                          KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,KC_ESC  , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,OS_MISC ,OS_FUNC ,_______ ,                          KC_TAB  ,_______ ,_______ ,_______ ,_______ , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,_______ ,KC_BSPC ,                          KC_ENT  ,_______ ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_FUNC] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                          KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_F11  ,_______ ,_______ ,_______ ,KC_PSCR ,                          KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,KC_F12  , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,_______ ,_______ ,                          _______ ,_______ ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_MISC] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,DF_QWER ,DF_SOUL ,DF_UKR  ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,_______ ,_______ ,                          _______ ,_______ ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_EXPR] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       KC_PERC ,KC_TILD ,KC_CIRC ,KC_DLR  ,KC_AT   ,                          _______ ,KC_LPRN ,KC_LBRC ,KC_RBRC ,KC_RPRN ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_ASTR ,KC_MINS ,KC_EQL  ,KC_COLN ,KC_PLUS ,                          KC_HASH ,OS_SFT  ,OS_CTL  ,OS_ALT  ,OS_GUI, 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_LT   ,KC_EXLM ,KC_PIPE ,KC_GT   ,KC_AMPR ,                          _______ ,KC_QUES ,KC_LCBR ,KC_RCBR ,KC_SLSH , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,KC_BSLS ,KC_BSPC ,                          _______ ,_______ ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    )
};

// Language change //
#define CHANGE_LANG tap_code16(LGUI(LCTL(KC_SPC)))
layer_state_t default_layer_state_set_user(layer_state_t state) {
    static uint8_t prev_layer = _QWERTY;

    uint8_t layer         = get_highest_layer(state);
    bool    should_toggle = false;
    switch (layer) {
        case _QWERTY ... _SOUL:
            should_toggle = prev_layer >= _UN;
            break;
        case _UN:
            should_toggle = prev_layer < _UN;
            break;
    }
    if (should_toggle) CHANGE_LANG;

    prev_layer = layer;
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    static layer_state_t prev_state    = 0;
    bool                 base_to_layer = layer_state_cmp(prev_state, 0) && !layer_state_cmp(state, 0);
    bool                 layer_to_base = !layer_state_cmp(prev_state, 0) && layer_state_cmp(state, 0);
    bool                 is_un         = get_highest_layer(default_layer_state) == _UN;
    if (is_un && (base_to_layer || layer_to_base)) {
        CHANGE_LANG;
    }

    prev_state = state;
    return state;
}
// **************************************************

// Oneshot layer(remove when qmk fixes layer lockout issue)

bool is_oneshot_layer_cancel_key(uint16_t keycode) {
    switch (keycode) {
        default:
            return false;
    }
}

bool is_oneshot_mod_key(uint16_t keycode) {
    return false;
}

oneshot_state os_nav_state  = os_up_unqueued;
oneshot_state os_func_state = os_up_unqueued;
oneshot_state os_misc_state = os_up_unqueued;
oneshot_state os_expr_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_repeat_key_with_alt(keycode, record, REPEAT, ALTREP)) { return false; }
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    bool handled = true;
    handled      = update_oneshot_layer(&os_nav_state, _NAV, OS_NAV, keycode, record) & handled;
    handled      = update_oneshot_layer(&os_func_state, _FUNC, OS_FUNC, keycode, record) & handled;
    handled      = update_oneshot_layer(&os_misc_state, _MISC, OS_MISC, keycode, record) & handled;
    handled      = update_oneshot_layer(&os_expr_state, _EXPR, OS_EXPR, keycode, record) & handled;

    if (!handled) return false;

    return true;
}

// **************************************************

const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOT , KC_UNDS}, // Shift . is _
  {KC_COMM, KC_SCLN}, // Shift , is ;
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);