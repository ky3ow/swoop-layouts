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

enum layers { QWERTY = 0, SOUL, UN, UN_EXTRA, NAV, SYM, NUM, LANGUAGE };

enum my_keys { MT_PLUS = SAFE_RANGE, MT_RCBR };

#define CTL_PLUS LCTL_T(MT_PLUS)
#define GUI_RCBR LGUI_T(MT_RCBR)

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case MT_PLUS:
      if (record->event.pressed && record->tap.count > 0) {
        tap_code16(KC_PLUS);
        return false;
      }
      break; 
    case MT_RCBR:
      if (record->event.pressed && record->tap.count > 0) {
        tap_code16(KC_RCBR);
        return false;
      }
      break; 
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
      LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), KC_F, KC_G, KC_H, KC_J, LGUI_T(KC_K), LALT_T(KC_L), LCTL_T(KC_SCLN),
      KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
      XXXXXXX, KC_SPC, XXXXXXX, TG(NAV), KC_LSFT, OSL(LANGUAGE)
    ),

    [SOUL] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_L, KC_D, KC_P, KC_K, KC_M, KC_U, KC_Y, KC_SCLN,
      LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_R), KC_T, KC_G, KC_F, KC_N, LGUI_T(KC_E), LALT_T(KC_I), LCTL_T(KC_O),
      KC_ESC, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_H, KC_COMM, KC_DOT, KC_SLSH,
      KC_J, KC_SPC, XXXXXXX, TG(NAV), KC_LSFT, OSL(LANGUAGE)
    ),

    [UN] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_P, KC_LBRC,
      LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), KC_F, KC_G, KC_H, KC_J, LGUI_T(KC_K), LALT_T(KC_L), LCTL_T(KC_SCLN),
      KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
      OSL(UN_EXTRA), KC_SPC, XXXXXXX, TG(NAV), KC_LSFT, OSL(LANGUAGE)
    ),

    [UN_EXTRA] = LAYOUT_split_3x5_3(
      _______, _______, _______, _______, KC_QUOT, _______, RSFT(KC_U), KC_O, _______, _______,
      _______, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      OSL(UN_EXTRA), KC_SPC, XXXXXXX, TG(NAV), KC_LSFT, OSL(LANGUAGE)
    ),

    [NAV] = LAYOUT_split_3x5_3(
      _______, _______, _______, _______, KC_PSCR, KC_ESC, KC_BSPC, KC_TAB, KC_INS, KC_DEL,
      KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, KC_ENT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
      _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
      XXXXXXX, _______, TO(0), TG(SYM), TG(NUM), XXXXXXX
    ),

    [SYM] = LAYOUT_split_3x5_3(
      KC_TILD, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_UNDS, KC_GRV,
      MT_PLUS, LALT_T(KC_MINUS), LGUI_T(KC_EQL), KC_ASTR, KC_COLN, KC_SCLN, KC_LCBR, MT_RCBR, LALT_T(KC_LBRC), LCTL_T(KC_RBRC),
      KC_LT, KC_EXLM, KC_PIPE, KC_GT, KC_AMPR, KC_DQUO, KC_QUOT, KC_COMM, KC_DOT, KC_QUES,
      KC_BSLS, _______, TO(0), TG(SYM), _______, KC_SLSH
    ),

    [NUM] = LAYOUT_split_3x5_3(
      KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
      KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_F6, KC_F12, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F11, KC_F10, KC_F9, KC_F8, KC_F7,
      XXXXXXX, _______, TO(0), TG(NUM), _______, XXXXXXX
    ),

    [LANGUAGE] = LAYOUT_split_3x5_3(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, DF(QWERTY), DF(SOUL), DF(UN), _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      XXXXXXX, KC_SPC, TO(0),  TG(NAV), KC_LSFT, XXXXXXX
    )

};
