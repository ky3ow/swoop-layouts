#include QMK_KEYBOARD_H

enum layers {
    // Base layers
    _QWERTY = 0,
    _UN,
    // Left hand layers
    _NAV,
    _FUNC,
    // Right hand layers
    _SYM
};

// ****
#define OS_SYM OSL(_SYM)
#define OS_NAV OSL(_NAV)
#define OS_FUNC OSL(_FUNC)
// ****
#define DF_QWER DF(_QWERTY)
#define DF_UKR DF(_UN)
// ****
#define MY_SPC  MT(MOD_LCTL, KC_SPC)
#define MY_BSPC  MT(MOD_LSFT, KC_BSPC)
// ****
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
       KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼─────────────────┘
                         OS_FUNC ,OS_NAV  ,MY_SPC  ,                          MY_BSPC ,OS_SYM  ,OS_ALT 
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_UN] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                          KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                          KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼─────────────────┘
                         OS_FUNC ,OS_NAV  ,MY_SPC  ,                          MY_BSPC ,OS_SYM  ,OS_ALT 
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_NAV] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                          KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       OS_GUI  ,OS_ALT  ,OS_CTL  ,OS_SFT  ,KC_PEQL ,                          KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,KC_TAB  , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_PDOT ,KC_PMNS ,KC_PPLS ,KC_PSLS ,KC_PAST ,                          KC_HASH ,KC_LBRC ,KC_LPRN ,KC_RPRN ,KC_RBRC , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼─────────────────┘
                         _______ ,_______ ,_______ ,                          KC_ENT  ,KC_ESC  ,KC_BSLS
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_FUNC] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                          KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       OS_GUI  ,OS_ALT  ,OS_CTL  ,OS_SFT  ,KC_PSCR ,                          KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,_______ , 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       _______ ,KC_DEL  ,_______ ,KC_INS  ,_______ ,                          _______ ,_______ ,_______ ,DF_QWER ,DF_UKR  , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         _______ ,_______ ,_______ ,                          KC_F11  ,KC_F12  ,_______
    //                  └────────┴────────┴────────┘                         └────────┴────────┴────────┘
    ),

    [_SYM] = LAYOUT_split_3x5_3(
    //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
       KC_PERC ,KC_TILD ,KC_CIRC ,KC_DLR  ,KC_AT   ,                          _______ ,KC_GRV  ,_______ ,_______ ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_ASTR ,KC_MINS ,KC_EQL  ,KC_COLN ,KC_PLUS ,                          _______ ,OS_SFT  ,OS_CTL  ,OS_ALT  ,OS_GUI, 
    //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
       KC_LT   ,KC_EXLM ,KC_PIPE ,KC_GT   ,KC_AMPR ,                          _______ ,_______ ,_______ ,KC_UNDS ,_______ , 
    //└─────────────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┘
                         KC_BSLS ,KC_DQUO ,KC_QUOT ,                          _______ ,_______ ,XXXXXXX
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
        case _QWERTY:
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
    bool                 base_to_sym = layer_state_cmp(prev_state, 0) && layer_state_cmp(state, _SYM);
    bool                 sym_to_base = layer_state_cmp(state, 0) && layer_state_cmp(prev_state, _SYM);
    bool                 is_un         = get_highest_layer(default_layer_state) == _UN;
    if (is_un && (base_to_sym || sym_to_base)) {
        CHANGE_LANG;
    }

    prev_state = state;
    return state;
}
// **************************************************
