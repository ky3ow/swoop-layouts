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
#include "keymap_ukrainian.h"

enum layers {
    _QWERTY = 0,
    _CMAK,
    _UKRAINE_QWERTY,
    _SYMBOL,
    _NAVIGATION,
    _NUMBER,
    _UN_EXTRA,
    _LANGUAGE
};

#define SYM_SPC LT(_SYMBOL, KC_SPC)
#define NAV_BSPC LT(_NAVIGATION, KC_BSPC)
#define NUM MO(_NUMBER)
#define LANG MO(_LANGUAGE)
#define UN _UKRAINE_QWERTY
#define UNE _UN_EXTRA
#define HCT LCTL_T
#define HA LALT_T
#define HCM LCMD_T
#define HS LSFT_T

// LT(layer, key) - layer on hold, key on tap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Qwerty
 * ,---------------------------------.     ,----------------------------------.
 * |  Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |  Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              | Tab  | Ent  | Spc  |     | BSpc | Esc  | Lang |
 *              `--------------------'     `--------------------'
 */

[_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q,      KC_W,      KC_E,      KC_R,   KC_T,         KC_Y,     KC_U,        KC_I,       KC_O,      KC_P,
  HCT(KC_A), HA(KC_S),  HCM(KC_D), KC_F,   KC_G,         KC_H,     KC_J,        HCM(KC_K),  HA(KC_L),  HCT(KC_SCLN),
  KC_Z,      KC_X,      KC_C,      KC_V,   KC_B,         KC_N,     KC_M,        KC_COMM,    KC_DOT,    KC_SLSH,
                        KC_TAB,    KC_ENT, SYM_SPC,      NAV_BSPC, HS(KC_ESC),  LANG
),

/*
 * Colemak dhv
 * ,---------------------------------.     ,----------------------------------.
 * |  Q  |   W  |   C  |   P  |   B  |     |   J  |   L  |   U  |   Y  |   ;  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  A  |   R  |   S  |   T  |   G  |     |   M  |   N  |   E  |   I  |   O  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |  Z  |   X  |   F  |   D  |   K  |     |   V  |   H  |   ,  |   .  |   /  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              | Tab  | Ent  | Spc  |     | BSpc | Esc  | Lang |
 *              `--------------------'     `--------------------'
 */

[_CMAK] = LAYOUT_split_3x5_3(
  KC_Q,       KC_W,      KC_C,      KC_P,      KC_B,          KC_J,     KC_L,       KC_U,       KC_Y,      KC_SCLN,
  HCT(KC_A),  HA(KC_R),  HCM(KC_S), KC_T,      KC_G,          KC_M,     KC_N,       HCM(KC_E),  HA(KC_I),  HCT(KC_O),
  KC_Z,       KC_X,      KC_F,      KC_D,      KC_K,          KC_V,     KC_H,       KC_COMM,    KC_DOT,    KC_SLSH,
                         KC_TAB,    KC_ENT,    SYM_SPC,       NAV_BSPC, HS(KC_ESC), LANG
),

/*
 * ЙЦУКЕН
 * ,---------------------------------.     ,-----------------------------------.
 * |  Й  |   Ц  |   У  |   К  |   E  |     |   H  |   Г  |   Ш  |   3  |   X   |
 * |-----+------+------+------+------|     |------+------+------+------+-------|
 * |  Ф  |   I  |   B  |   A  |   П  |     |   P  |   O  |   Л  |   Д  |   Ж   |
 * |-----+------+------+------+------|     ,------+------+------+------+-------|
 * |  Я  |   Ч  |   C  |   M  |   И  |     |   T  |   Ь  |   Б  |   Ю  | Extra |
 * `------------+------+------+------|     |------+------+------+--------------'
 *              | Tab  | Ent  | Spc  |     | BSpc | Esc  | Lang |
 *              `--------------------'     `--------------------'
 */

[_UKRAINE_QWERTY] = LAYOUT_split_3x5_3(
  UA_YOT,      UA_TSE,    UA_U,       UA_KA,   UA_E,          UA_EN,    UA_HE,      UA_SHA,     UA_ZE,     UA_KHA,
  HCT(UA_EF),  HA(UA_I),  HCM(UA_VE), UA_A,    UA_PE,         UA_ER,    UA_O,       HCM(UA_EL), HA(UA_DE), HCT(UA_ZHE),
  UA_YA,       UA_CHE,    UA_ES,      UA_EM,   UA_Y,          UA_TE,    UA_SOFT,    UA_BE,      UA_YU,     OSL(UNE),
                          KC_TAB,     KC_ENT,  SYM_SPC,       NAV_BSPC, HS(KC_ESC), LANG
),

/*
 * Symbol
 * ,---------------------------------.     ,----------------------------------.
 * |  !  |   @  |   #  |   $  |   %  |     |   ^  |   &  |   *  |   -  |   +  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  _  |   (  |   {  |   [  |   <  |     |   >  |   ]  |   }  |   )  |   =  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |  ,  |   |  |   "  |   ~  |   :  |     |   ;  |   `  |   '  |   ?  |   .  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              |      |      |      |     | Num  |   \  |   /  |
 *              `--------------------'     `--------------------'
 * ,---------------------------------.     ,----------------------------------.
 * |  !  |   @  |   #  |   $  |   %  |     |   ^  |   &  |   *  |   _  |   +  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  [  |   ,  |   -  |   =  |   <  |     |   >  |   :  |   ;  |   .  |   ]  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |  "  |   ~  |   (  |   {  |   |  |     |   ?  |   }  |   )  |   `  |   '  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              |      |      |      |     | Num  |   \  |   /  |
 *              `--------------------'     `--------------------'
 */

[_SYMBOL] = LAYOUT_split_3x5_3(
  KC_EXLM,       KC_AT,       KC_HASH,       KC_DLR,  KC_PERC,        KC_CIRC,   KC_AMPR,   KC_ASTR,      KC_UNDS,    KC_PLUS,
  HCT(KC_LBRC),  HA(KC_COMM), HCM(KC_MINUS), KC_EQL,  KC_LT,          KC_GT,     KC_COLN,   HCM(KC_SCLN), HA(KC_DOT), HCT(KC_RBRC),
  KC_DQUO,       KC_TILDE,    KC_LPRN,       KC_LCBR, KC_PIPE,        KC_QUES,   KC_RCBR,   KC_RPRN,      KC_GRV,     KC_QUOT,
                             _______,      _______,   _______,        NUM,       KC_SLSH,   KC_BSLS 
),

/*
 * Navigation
 * ,---------------------------------.     ,----------------------------------.
 * | ESC |      |      |      |      |     | PSCR | HOME | PGDN | PGUP | END  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * | SFT | TAB  |      |      |      |     |  ENT |   L  |   D  |   U  |   R  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * | CTR |      |      |      |      |     |      |      |      |      |      |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              | Cmd  | Alt  | Num  |     |      |      |      |
 *              `--------------------'     `--------------------'
 */

[_NAVIGATION] = LAYOUT_split_3x5_3(
  KC_ESC,   _______,   _______,  _______,  _______,     KC_PSCR,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,
  KC_LSFT,  KC_TAB,    _______,  _______,  _______,     KC_ENT,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  
  KC_LCTL,  _______,   _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,
                       KC_LCMD,  KC_LALT,  NUM,         _______,  _______,  _______   
),

/*
 * Number
 * ,---------------------------------.     ,----------------------------------.
 * |  1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * | CTL |  ALT | CMD  | SFT  | F11  |     |  F12 | SFT  | CMD  |  ALT | CTL  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |  F1 |   F2 |   F3 |   F4 |  F5  |     |  F6  |  F7  |  F8  |  F9  |  F10 |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              |      |      |      |     |      |      |      |
 *              `--------------------'     `--------------------'
 */

[_NUMBER] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
  KC_LCTL, KC_LALT,  KC_LCMD,  KC_LSFT,  KC_F11,      KC_F12,   KC_LSFT,  KC_LCMD,  KC_LALT,  KC_LCTL,
  KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
                     _______,  _______,  _______,     _______,  _______,  _______
),

/*
 * ЙЦУКЕН Extra
 *
 * ,---------------------------------.     ,----------------------------------.
 * |     |      |      |      |  Є   |     |      |   Ґ  |   Щ  |      |      |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |     |  Ї   |      |      |      |     |      |      |      |      |      |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |     |      |      |      |      |     |      |      |      |      |      |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              |      |      |      |     |      |      |      |
 *              `--------------------'     `--------------------'
 */

[_UN_EXTRA] = LAYOUT_split_3x5_3(
  _______,  _______,   _______,  _______,  UA_YE,       _______,  UA_GE,    UA_SHCH,  _______,  _______,
  _______,  UA_YI,     _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,
  _______,  _______,   _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,
                       _______,  _______,  _______,     _______,  _______,  _______   
),

/*
 * Language
 * Ln - change default layout to Ln
 * ,---------------------------------.     ,----------------------------------.
 * |     |      |      |      |      |     |      |      |      |      |      |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * | L1  |  L2  |  L3  |      |      |     |      |      |  &m  |  m^  |  m$  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * | Ctr | Alt  | Cmd  | Shf  |      |     |      |      |      |      |      |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              |      |      |      |     |      |      |      |
 *              `--------------------'     `--------------------'
 */

[_LANGUAGE] = LAYOUT_split_3x5_3(
  _______,      _______,   _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,
  DF(_QWERTY),  DF(_CMAK), DF(UN),   _______,  _______,     _______,  _______,  DM_PLY1,  DM_REC1,  DM_RSTP,
  KC_LCTL,      KC_LALT,   KC_LCMD,  KC_LSFT,  _______,     _______,  _______,  _______,  _______,  _______,
                           _______,  _______,  _______,     _______,  _______,  _______   
)

};
