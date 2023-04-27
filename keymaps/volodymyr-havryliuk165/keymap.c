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

enum layers { QWERTY = 0, SOUL, UN, SYM };

enum my_keys { TO_BASE = SAFE_RANGE, TO_QWERTY, TO_SOUL, TO_UN, TO_SYM };

#define CHANGE_LANG tap_code16(LGUI(LCTL(KC_SPC)))

layer_state_t default_layer_state_set_user(layer_state_t state) {
    CHANGE_LANG;
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    static bool in_ukrainian = false;

    if (record->event.pressed) {
        switch (keycode) {
            case TO_BASE:
                if (in_ukrainian) {
                    CHANGE_LANG;
                }
                layer_clear();
                return false;
            case TO_QWERTY:
                in_ukrainian = false;
                default_layer_set(1U << QWERTY);
                return false;
            case TO_SOUL:
                in_ukrainian = false;
                default_layer_set(1U << SOUL);
                return false;
            case TO_UN:
                in_ukrainian = true;
                default_layer_set(1U << UN);
                return false;
            case TO_SYM:
                if (in_ukrainian) {
                    CHANGE_LANG;
                }
                layer_on(SYM);
                return true;
            default:
                return true;
        }
    }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,---------------------------------.     ,----------------------------------.
     * |  Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |
     * |-----+------+------+------+------|     |------+------+------+------+------|
     * |  A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |
     * |-----+------+------+------+------|     ,------+------+------+------+------|
     * |  Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |
     * `------------+------+------+------|     |------+------+------+-------------'
     *              | LCTL | BSpc | Esc  |     | Ent  | Spc  | LAlt |
     *              `--------------------'     `--------------------'
     */

    [QWERTY] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I, KC_O, KC_P,
      KC_A, KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K, KC_L, KC_SCLN, 
      KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
       KC_LCTL, KC_BSPC, TO_SOUL,     TO_UN, TO_SYM, KC_LALT),

    /*
     * SOUL
     * ,---------------------------------.     ,----------------------------------.
     * |  Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |
     * |-----+------+------+------+------|     |------+------+------+------+------|
     * |  A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |
     * |-----+------+------+------+------|     ,------+------+------+------+------|
     * |  Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |
     * `------------+------+------+------|     |------+------+------+-------------'
     *              | LCTL | BSpc | Esc  |     | Ent  | Spc  | LAlt |
     *              `--------------------'     `--------------------'
     */
    [SOUL] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_L, KC_D, KC_P,   KC_K, KC_M, KC_U, KC_Y, KC_SCLN,
      KC_A, KC_S, KC_R, KC_T, KC_G,   KC_F, KC_N, KC_E, KC_I, KC_O,
      KC_Z, KC_X, KC_C, KC_V, KC_J,   KC_B, KC_H, KC_COMM, KC_DOT, KC_SLSH,
       KC_LCTL, KC_BSPC, TO_SOUL,     TO_UN, TO_SYM, KC_LALT),

    /*
     * ЙЦУКЕН
     * ,---------------------------------.     ,----------------------------------.
     * |  Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |
     * |-----+------+------+------+------|     |------+------+------+------+------|
     * |  A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |
     * |-----+------+------+------+------|     ,------+------+------+------+------|
     * |  Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |
     * `------------+------+------+------|     |------+------+------+-------------'
     *              | LCTL | BSpc | Esc  |     | Ent  | Spc  | LAlt |
     *              `--------------------'     `--------------------'
     */
    [UN] = LAYOUT_split_3x5_3(
     KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I, KC_P, KC_LBRC,
     KC_A, KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K, KC_L, KC_SCLN,
     KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
     KC_LCTL, KC_BSPC, TO_SOUL,     TO_UN, TO_SYM, KC_LALT),

    /*
     * ЙЦУКЕН
     * ,---------------------------------.     ,----------------------------------.
     * |  Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |
     * |-----+------+------+------+------|     |------+------+------+------+------|
     * |  A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |
     * |-----+------+------+------+------|     ,------+------+------+------+------|
     * |  Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |
     * `------------+------+------+------|     |------+------+------+-------------'
     *              | LCTL | BSpc | Esc  |     | Ent  | Spc  | LAlt |
     *              `--------------------'     `--------------------'
     */
    [SYM] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_E,     KC_R,    KC_T,        KC_Y,    KC_U,   KC_I,    KC_P, KC_LBRC,
      KC_A, KC_S, KC_D,     KC_LCBR,    KC_G,        KC_H,    KC_RCBR,   KC_K,    KC_L, KC_SCLN, 
      KC_Z, KC_X, KC_C,     KC_V,    KC_B,        KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH,
                  KC_LCTL,  KC_BSPC, TO_SOUL,     TO_UN,   TO_SYM, KC_LALT
    )};
