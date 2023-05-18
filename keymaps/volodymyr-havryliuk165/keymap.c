#include QMK_KEYBOARD_H

// Features
#include "features/repeat_key.h"
#include "features/oneshot.h"

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
    _EXPR,
    _PROG,
    // Both hand layers
    _NUM,
};

enum custom_keycodes {
    // Repeat and reverse repeat keys
    REPEAT = SAFE_RANGE,
    ALTREP,
    // One shot layers because OSL is broken rn
    OS_NAV,
    OS_FUNC,
    OS_MISC,
    OS_EXPR,
    OS_PROG,
    OS_NUM
};

#define DF_SOUL DF(_SOUL)
#define DF_QWER DF(_QWERTY)
#define DF_UKR DF(_UN)

#define OS_SFT OSM(MOD_LSFT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_WEZ OSM(MOD_LCTL | MOD_LSFT)
// **************************************************

// Combos
enum combos { C_J, C_V, C_B, C_UNDS, C_PERC, C_QUES, C_LEN };
uint16_t COMBO_LEN = C_LEN;

const uint16_t PROGMEM combj[]      = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combv[]      = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combb[]      = {KC_H, KC_DOT, COMBO_END};
const uint16_t PROGMEM combunds[]   = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combperc[]   = {KC_TILD, KC_CIRC, COMBO_END};
const uint16_t PROGMEM combques[]   = {KC_EXLM, KC_PIPE, COMBO_END};

combo_t key_combos[] = {
    // Soul combos
    [C_J]    = COMBO(combj, KC_J),
    [C_V]    = COMBO(combv, KC_V),
    [C_B]    = COMBO(combb, KC_B),
    [C_UNDS] = COMBO(combunds, KC_UNDS),
    // Expr layer combos
    [C_PERC] = COMBO(combperc, KC_PERC),
    [C_QUES] = COMBO(combques, KC_QUES)
};
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
                         XXXXXXX ,OS_EXPR ,KC_SPC  ,                          REPEAT  ,OS_NAV  ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_SOUL] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       KC_Q    ,KC_W    ,KC_L    ,KC_D    ,KC_P    ,                          KC_K    ,KC_M    ,KC_U    ,KC_Y    ,KC_QUOT ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_A    ,KC_S    ,KC_R    ,KC_T    ,KC_G    ,                          KC_F    ,KC_N    ,KC_E    ,KC_I    ,KC_O    , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,KC_Z    ,KC_X    ,KC_C    ,XXXXXXX ,                          XXXXXXX ,KC_H    ,KC_COMM ,KC_DOT  ,XXXXXXX , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,OS_EXPR ,KC_SPC  ,                          REPEAT  ,OS_NAV  ,XXXXXXX
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
                         XXXXXXX ,OS_EXPR ,KC_SPC  ,                          REPEAT  ,OS_NAV  ,XXXXXXX
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
       _______ ,KC_TAB  ,KC_UP   ,KC_ENT  ,_______ ,                          _______ ,REPEAT  ,_______ ,ALTREP  ,OS_WEZ  ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_ESC  ,KC_LEFT ,KC_DOWN ,KC_RIGHT,_______ ,                          _______ ,OS_SFT  ,OS_GUI  ,OS_ALT  ,OS_CTL  , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,_______ ,_______ ,_______ ,XXXXXXX ,                          XXXXXXX ,OS_FUNC ,OS_MISC ,_______ ,XXXXXXX , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,OS_NUM  ,KC_BSPC ,                          _______ ,_______ ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_FUNC] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       _______ ,_______ ,KC_PGUP ,KC_INS  ,KC_PSCR ,                          KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_DEL  ,KC_HOME ,KC_PGDN ,KC_END  ,_______ ,                          KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,_______ ,_______ ,_______ ,XXXXXXX ,                          XXXXXXX ,_______ ,KC_F11  ,KC_F12  ,XXXXXXX , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,_______ ,_______ ,                          _______ ,_______ ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_MISC] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       _______ ,DF_QWER ,DF_SOUL ,DF_UKR  ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
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
       OS_WEZ  ,KC_LBRC ,KC_RBRC ,_______ ,_______ ,                          KC_PLUS ,KC_TILD ,KC_CIRC ,KC_DLR  ,KC_ASTR ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       OS_CTL  ,OS_ALT  ,OS_GUI  ,OS_SFT  ,_______ ,                          KC_AMPR ,KC_COLN ,KC_EQL  ,KC_MINS ,KC_GT   , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,_______ ,_______ ,OS_PROG ,XXXXXXX ,                          XXXXXXX ,KC_LT   ,KC_PIPE ,KC_EXLM ,XXXXXXX , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,_______ ,_______ ,                          _______ ,OS_NUM  ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_PROG] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       _______ ,_______ ,_______ ,_______ ,_______ ,                          KC_GRV  ,KC_LBRC ,KC_HASH ,KC_RBRC ,KC_DQUO ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,_______ ,                          KC_AT   ,KC_LPRN ,KC_BSLS ,KC_RPRN ,KC_SCLN , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,_______ ,_______ ,_______ ,XXXXXXX ,                          XXXXXXX ,KC_LCBR ,KC_SLSH ,KC_RCBR ,XXXXXXX , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,_______ ,_______ ,                          _______ ,_______ ,XXXXXXX
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_NUM] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       OS_WEZ  ,_______ ,_______ ,_______ ,_______ ,                          _______ ,KC_7    ,KC_8    ,KC_9    ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       OS_CTL  ,OS_ALT  ,OS_GUI  ,OS_SFT  ,_______ ,                          _______ ,KC_4    ,KC_5    ,KC_6    ,KC_0    , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,_______ ,_______ ,_______ ,XXXXXXX ,                          XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,XXXXXXX , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         XXXXXXX ,_______ ,_______ ,                          _______ ,_______ ,XXXXXXX
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
oneshot_state os_prog_state = os_up_unqueued;
oneshot_state os_num_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_repeat_key_with_alt(keycode, record, REPEAT, ALTREP)) {
        return false;
    }
    bool handled = true;
    handled      = update_oneshot_layer(&os_nav_state, _NAV, OS_NAV, keycode, record) & handled;
    handled      = update_oneshot_layer(&os_func_state, _FUNC, OS_FUNC, keycode, record) & handled;
    handled      = update_oneshot_layer(&os_misc_state, _MISC, OS_MISC, keycode, record) & handled;
    handled      = update_oneshot_layer(&os_expr_state, _EXPR, OS_EXPR, keycode, record) & handled;
    handled      = update_oneshot_layer(&os_expr_state, _PROG, OS_PROG, keycode, record) & handled;
    handled      = update_oneshot_layer(&os_expr_state, _NUM, OS_NUM, keycode, record) & handled;

    if (!handled) return false;

    return true;
}

// **************************************************