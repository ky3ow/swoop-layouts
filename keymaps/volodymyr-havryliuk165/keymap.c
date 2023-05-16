/* Copyright 2022 James White <jamesmnw@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "features/repeat_key.h"
#define CHANGE_LANG tap_code16(LGUI(LCTL(KC_SPC)))

enum layers { _QWERTY = 0, _SOUL, _UN, _UN_EXTRA, _NAVIGATION, _SYMBOL, _SYSTEM, _LANGUAGE };

enum custom_keycodes {
  REPEAT = SAFE_RANGE,
  ALTREP
};

// Combos start //
enum combos {
  COMBO_J,
  COMBO_V,
  COMBO_B,
  COMBO_UNDS,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combj[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combv[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combb[] = {KC_H, KC_DOT, COMBO_END};
const uint16_t PROGMEM combunds[] = {KC_U, KC_Y, COMBO_END};
combo_t key_combos[] = {
  [COMBO_J] = COMBO(combj, KC_J),
  [COMBO_V] = COMBO(combv, KC_V),
  [COMBO_B] = COMBO(combb, KC_B),
  [COMBO_UNDS] = COMBO(combunds, KC_UNDS),
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // switch (index) {
    //     case COMBO_CTL:
    //         return 200;
    // }
    return COMBO_TERM;
}

// Combos end //

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
    static bool sym_on = false;
    if (sym_on != IS_LAYER_ON_STATE(state, _SYMBOL)) {
      sym_on = !sym_on;
      if(get_highest_layer(default_layer_state) >= _UN) CHANGE_LANG;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_repeat_key_with_alt(keycode, record, REPEAT, ALTREP)) { return false; }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
      KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
      KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_QUES,
      XXXXXXX, OSL(_SYMBOL), KC_SPC, REPEAT, OSL(_NAVIGATION), XXXXXXX
    ),

    [_SOUL] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_L, KC_D, KC_P, KC_K, KC_M, KC_U, KC_Y, KC_QUOT,
      KC_A, KC_S, KC_R, KC_T, KC_G, KC_F, KC_N, KC_E, KC_I, KC_O,
      XXXXXXX, KC_Z, KC_X, KC_C, XXXXXXX, XXXXXXX, KC_H, KC_COMM, KC_DOT, XXXXXXX,
      XXXXXXX, OSL(_SYMBOL), KC_SPC, REPEAT, OSL(_NAVIGATION), XXXXXXX
    ),

    [_UN] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_P, KC_LBRC,
      KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
      KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_QUES,
      XXXXXXX, OSL(_SYMBOL), KC_SPC, REPEAT, OSL(_NAVIGATION), XXXXXXX
    ),

    [_UN_EXTRA] = LAYOUT_split_3x5_3(
      _______, _______, _______, _______, KC_QUOT, _______, RALT(KC_U), KC_O, _______, _______,
      _______, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______ 
    ),

    [_NAVIGATION] = LAYOUT_split_3x5_3(
      _______, KC_TAB, KC_UP, KC_ENT, _______, _______, REPEAT, _______, ALTREP, _______,
      KC_ESC, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), 
      XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX,
      XXXXXXX, OSL(_SYSTEM), KC_BSPC, OSL(_LANGUAGE), _______, XXXXXXX
    ),

    [_SYMBOL] = LAYOUT_split_3x5_3(
      KC_PERC, KC_TILD, KC_CIRC, KC_DLR, XXXXXXX,      XXXXXXX, KC_LPRN, KC_HASH, KC_RPRN, KC_GRV, 
      KC_LT, KC_MINUS, KC_EQL, KC_COLN, KC_ASTR,       KC_BSLS, KC_LBRC, KC_QUOT, KC_RBRC,  KC_SCLN,
      XXXXXXX, KC_EXLM, KC_PIPE, KC_GT, KC_AMPR,       KC_AT, KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
      XXXXXXX, MO(_SYSTEM), OSM(MOD_LSFT), XXXXXXX, _______, XXXXXXX 
    ),

    [_SYSTEM] = LAYOUT_split_3x5_3(
      _______, _______, KC_PGUP, _______, XXXXXXX,     XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10,
      _______, KC_HOME, KC_PGDN, KC_END, KC_PSCR,      KC_F12, KC_F4, KC_F5, KC_F6, KC_F11,
      XXXXXXX, _______, KC_DEL, KC_INS,  _______,      _______, KC_F1, KC_F2, KC_F3, XXXXXXX,
      XXXXXXX, _______, _______, _______, _______, XXXXXXX 
    ), 

    [_LANGUAGE] = LAYOUT_split_3x5_3(
      _______, DF(_QWERTY), DF(_SOUL), DF(_UN), XXXXXXX, XXXXXXX, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
      XXXXXXX, _______, _______, _______, _______, XXXXXXX 
    )


};
