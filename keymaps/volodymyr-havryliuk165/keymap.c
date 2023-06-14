#include QMK_KEYBOARD_H
// #include "features/repeat_key.h"

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
#define OS_SFT OSM(MOD_LSFT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)

// **************************************************
// enum custom_keycodes {
//   QK_REP = SAFE_RANGE,
//   QK_AREP
// };

// **************************************************
const uint16_t PROGMEM test_combo1[] = {OS_NAV, KC_SPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, OS_FUNC)
};

uint16_t COMBO_LEN = 1;

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
                         QK_REP  ,OS_NAV  ,KC_SPC  ,                          QK_AREP ,OS_SYM  ,KC_BSPC
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
                         QK_REP  ,OS_NAV  ,KC_SPC  ,                          QK_AREP ,OS_SYM  ,KC_BSPC
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
    bool                 base_to_nav = layer_state_cmp(prev_state, 0) && layer_state_cmp(state, _NAV);
    bool                 nav_to_base = layer_state_cmp(state, 0) && layer_state_cmp(prev_state, _NAV);
    bool                 is_un         = get_highest_layer(default_layer_state) == _UN;
    if (is_un && (base_to_sym || sym_to_base || base_to_nav || nav_to_base)) {
        CHANGE_LANG;
    }

    prev_state = state;
    return state;
}
// **************************************************

// Repeat //

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  if((mods & MOD_MASK_CTRL)) {
   switch(keycode) {
      case KC_D: return C(KC_U);
      case KC_U: return C(KC_D);
   }
  }
  switch (keycode) {
    case KC_E: return KC_D;  // For "ED" bigram.
    case KC_D: return KC_E;  // For "DE" bigram.
    case KC_C: return KC_E;  // For "CE" bigram.
    case KC_L: return KC_O;  // For "LO" bigram.
    case KC_U: return KC_N;  // For "UN" bigram.
    case KC_M: return KC_U;  // For "MU" bigram.
  }
  return KC_TRNS;
}

// bool process_record_user(uint16_t keycode, keyrecord_t* record) {
//   if (!process_repeat_key_with_alt(keycode, record, QK_REP, QK_AREP)) { return false; }

//   return true;
// }

// **************************************************