/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    WIN_MSE,
};

enum custom_keycodes {
    DEGREE = NEW_SAFE_RANGE,
    EN_DASH,
    EM_DASH,
    MICRO,
};

#undef KC_TASK
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MCAP LT(WIN_MSE,KC_CAPS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_84(
/*   Esc       F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12       PrtSc     Delete    Lights  */
     KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNAP,  KC_DEL,   RGB_MOD,
/*   `         1         2         3         4         5         6         7         8         9         0         -         =         Bksp                PgUp    */
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
/*   Tab       Q         W         E         R         T         Y         U         I         O         P         [         ]         \                   PgDn    */
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
/*   Caps      A         S         D         F         G         H         J         K         L         ;         '                   Enter               Home    */
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
/*   Shift               Z         X         C         V         B         N         M         ,         .         /                   Shift     Up        End     */
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
/*   Ctrl      Gui       Alt                                     Space                                   Alt       WIN_FN    Ctrl      Left      Down      Rght    */
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD,MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_ansi_84(
/*   Esc       F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12       PrtSc     Delete    Lights  */
     _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  RGB_TOG,
/*   `         1         2         3         4         5         6         7         8         9         0         -         =         Bksp                PgUp    */
     _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
/*   Tab       Q         W         E         R         T         Y         U         I         O         P         [         ]         \                   PgDn    */
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
/*   Caps      A         S         D         F         G         H         J         K         L         ;         '                   Enter               Home    */
     _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
/*   Shift               Z         X         C         V         B         N         M         ,         .         /                   Shift     Up        End     */
     _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
/*   Ctrl      Gui       Alt                                     Space                                   Alt       WIN_FN    Ctrl      Left      Down      Rght    */
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

[WIN_BASE] = LAYOUT_ansi_84(
/*   Esc       F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12       PrtSc     Delete    Lights  */
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   RGB_MOD,
/*   `         1         2         3         4         5         6         7         8         9         0         -         =         Bksp                PgUp    */
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
/*   Tab       Q         W         E         R         T         Y         U         I         O         P         [         ]         \                   PgDn    */
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
/*   Caps      A         S         D         F         G         H         J         K         L         ;         '                   Enter               Home    */
     KC_MCAP,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
/*   Shift               Z         X         C         V         B         N         M         ,         .         /                   Shift     Up        End     */
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
/*   Ctrl      Gui       Alt                                     Space                                   Alt       WIN_FN    Ctrl      Left      Down      Rght    */
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_ansi_84(
/*   Esc       F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12       PrtSc     Delete    Lights  */
     _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  RGB_TOG,
/*   `         1         2         3         4         5         6         7         8         9         0         -         =         Bksp                PgUp    */
     _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
/*   Tab       Q         W         E         R         T         Y         U         I         O         P         [         ]         \                   PgDn    */
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  MICRO,    _______,  DEGREE,   _______,  _______,  _______,  _______,            _______,
/*   Caps      A         S         D         F         G         H         J         K         L         ;         '                   Enter               Home    */
   TG(WIN_MSE),RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  DM_PLY1,  DM_PLY2,  _______,            _______,            _______,
/*   Shift               Z         X         C         V         B         N         M         ,         .         /                   Shift     Up        End     */
     _______,            NK_TOGG,  _______,  _______,  _______,  BAT_LVL,  EN_DASH,  EM_DASH,  DM_REC1,  DM_REC2,  DM_RSTP,            _______,  _______,  _______,
/*   Ctrl      Gui       Alt                                     Space                                   Alt       WIN_FN    Ctrl      Left      Down      Rght    */
     _______,  _______,  _______,                                _______,                              TG(WIN_MSE),_______,  _______,  _______,  _______,  _______),

[WIN_MSE] = LAYOUT_ansi_84(
/*   Esc       F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12       PrtSc     Delete    Lights  */
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
/*   `         1         2         3         4         5         6         7         8         9         0         -         =         Bksp                PgUp    */
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
/*   Tab       Q         W         E         R         T         Y         U         I         O         P         [         ]         \                   PgDn    */
     _______,  _______,  KC_WH_U,  KC_WH_L,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
/*   Caps      A         S         D         F         G         H         J         K         L         ;         '                   Enter               Home    */
   TG(WIN_MSE),KC_BTN1,  KC_BTN3,  KC_BTN2,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
/*   Shift               Z         X         C         V         B         N         M         ,         .         /                   Shift     Up        End     */
     _______,            _______,  KC_WH_D,  KC_WH_R,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  KC_MS_U,  _______,
/*   Ctrl      Gui       Alt                                     Space                                   Alt       WIN_FN    Ctrl      Left      Down      Rght    */
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R),
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode < NEW_SAFE_RANGE) {
        if (!process_record_keychron_common(keycode, record)) {
            return false;
        }
        return true;
    } else {
        switch (keycode) {
        case DEGREE:
            // Alt + 0176
            if (record->event.pressed) {
                register_code(KC_RALT);
                tap_code(KC_P0);
                tap_code(KC_P1);
                tap_code(KC_P7);
                tap_code(KC_P6);
                unregister_code(KC_RALT);
            }
            break;
        case EN_DASH:
            // Alt + 0150
            if (record->event.pressed) {
                register_code(KC_RALT);
                tap_code(KC_P0);
                tap_code(KC_P1);
                tap_code(KC_P5);
                tap_code(KC_P0);
                unregister_code(KC_RALT);
            }
            break;
        case EM_DASH:
            // Alt + 0151
            if (record->event.pressed) {
                register_code(KC_RALT);
                tap_code(KC_P0);
                tap_code(KC_P1);
                tap_code(KC_P5);
                tap_code(KC_P1);
                unregister_code(KC_RALT);
            }
            break;
        case MICRO:
            // Alt + 0181
            if (record->event.pressed) {
                register_code(KC_RALT);
                tap_code(KC_P0);
                tap_code(KC_P1);
                tap_code(KC_P8);
                tap_code(KC_P1);
                unregister_code(KC_RALT);
            }
            break;
        }
    }
    return true;
}
