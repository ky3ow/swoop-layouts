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

enum layers { QWERTY = 0, SOUL, UN, UN_EXTRA, NAV, SYM, SYS };

#define CHANGE_LANG tap_code16(LGUI(LCTL(KC_SPC)))

layer_state_t default_layer_state_set_user(layer_state_t state) {
    static uint8_t prev_layer = QWERTY;

    uint8_t layer         = get_highest_layer(state);
    bool    should_toggle = false;
    switch (layer) {
        case QWERTY ... SOUL:
            should_toggle = prev_layer >= UN;
            break;
        case UN:
            should_toggle = prev_layer < UN;
            break;
    }
    if (should_toggle) CHANGE_LANG;

    prev_layer = layer;
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    static bool sym_on = false;
    if (sym_on != IS_LAYER_ON_STATE(state, SYM)) {
      sym_on = !sym_on;
      if(get_highest_layer(default_layer_state) >= UN) CHANGE_LANG;
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
      KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
      KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
      XXXXXXX, LT(SYS, KC_ESC), LT(NAV, KC_SPC), LT(SYM, KC_BSPC), KC_ENT, XXXXXXX
    ),

    [SOUL] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_L, KC_D, KC_P, KC_K, KC_M, KC_U, KC_Y, KC_SCLN,
      KC_A, KC_S, KC_R, KC_T, KC_G, KC_F, KC_N, KC_E, KC_I, KC_O,
      XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_H, KC_COMM, KC_DOT, KC_SLSH,
      KC_J, LT(SYS, KC_ESC), LT(NAV, KC_SPC), LT(SYM, KC_BSPC), KC_ENT, XXXXXXX
    ),

    [UN] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_P, KC_LBRC,
      KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
      KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
      OSL(UN_EXTRA), LT(SYS, KC_ESC), LT(NAV, KC_SPC), LT(SYM, KC_BSPC), KC_ENT, XXXXXXX
    ),

    [UN_EXTRA] = LAYOUT_split_3x5_3(
      _______, _______, _______, _______, KC_QUOT, _______, RALT(KC_U), KC_O, _______, _______,
      _______, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______ 
    ),

    [NAV] = LAYOUT_split_3x5_3(
      KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
      OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), KC_TAB, KC_ESC, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
      KC_PPLS, KC_PMNS, KC_PEQL, KC_PAST, KC_PSLS, KC_PDOT, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
      XXXXXXX, XXXXXXX, _______, _______, _______, _______ 
    ),

    [SYM] = LAYOUT_split_3x5_3(
      KC_TILD, KC_AT, KC_CIRC, KC_DLR, KC_PERC, KC_BSLS, KC_SLSH, KC_RPRN, KC_LPRN, KC_GRV,
      KC_PLUS, KC_MINUS, KC_EQL, KC_ASTR, KC_COLN, KC_SCLN, KC_LCBR, KC_RCBR, KC_UNDS, KC_HASH,
      KC_LT, KC_EXLM, KC_PIPE, KC_GT, KC_AMPR, KC_QUES, KC_LBRC, KC_RBRC, KC_COMM, KC_DOT, 
      XXXXXXX, KC_QUOT, KC_DQUO, _______, XXXXXXX, XXXXXXX 
    ),

    [SYS] = LAYOUT_split_3x5_3(
      _______, DF(QWERTY), DF(SOUL), DF(UN), KC_PSCR, KC_DEL, KC_INS, _______, _______, _______,
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
      _______, _______, _______, _______, KC_F11, KC_F12, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______ 
    )

};
