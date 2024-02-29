/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers{
  DVORAK,
  BASE,
  FN,
  NUM,
  MOUSE_L,
};

enum custom_keycodes {
    ISS_MAN = SAFE_RANGE,
    ISS_APP,
    KEY_MJB,
    PAST_TB,
    DEGREE,
    EN_DASH,
    EM_DASH,
    MICRO,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ISS_MAN:
        if (record->event.pressed) {
            SEND_STRING("ISSUED FOR MANUFACTURE\t");
        }
        break;
    case ISS_APP:
        if (record->event.pressed) {
            SEND_STRING("ISSUED FOR APPROVAL\t");
        }
        break;
    case KEY_MJB:
        if (record->event.pressed) {
            SEND_STRING("MJB\t");
        }
        break;
    case PAST_TB:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("v") "\t");
        }
        break;
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
    return true;
}

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MCAP LT(MOUSE_L,KC_CAPS)

const uint16_t PROGMEM caps_word_combo[] = {KC_LSFT, KC_MCAP, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(caps_word_combo, CW_TOGG),
};

/*
        Esc       F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12         Knob        PrtSc     Mic       Lights    Circle    Tri       Square    Cross

        `         1         2         3         4         5         6         7         8         9         0         -         =           Bksp        Ins       Home      Pgup      Num       /         *         -

        Tab       Q         W         E         R         T         Y         U         I         O         P         [         ]           \           Del       End       Pgdn      7         8         9         +

        Caps      A         S         D         F         G         H         J         K         L         ;         '                     Enter                                     4         5         6

        Shift               Z         X         C         V         B         N         M         ,         .         /                     Shift                 Up                  1         2         3         Enter

        Ctrl      Gui       Alt                                     Space                                   Alt       Gui       Fn          Ctrl        Left      Down      Rght      0                   .
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DVORAK] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MUTE,  KC_PSCR,  KC_PAUS,  RGB_MOD,  KC_BSPC,  KC_DEL,   KC_MPLY,  KC_MSEL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LBRC,  KC_RBRC,  KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_SCLN,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,  KC_EQL,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        KC_MCAP,  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,            KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,
        KC_LSFT,            KC_QUOT,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,               KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        LM(BASE, MOD_LCTL),LM(BASE, MOD_LGUI),LM(BASE, MOD_LALT),   KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(FN),   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT),
    [BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MUTE,  KC_PSCR,  KC_PAUS,  RGB_MOD,  KC_BSPC,  KC_DEL,   KC_MPLY,  KC_MSEL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        KC_MCAP,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(FN),   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT),
    [FN] = LAYOUT_ansi_109(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_TOG,  _______,  QK_LOCK,  KC_SCRL,  _______,  _______,  _______,  _______,
        QK_RBT,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_CALC,  _______,  DEGREE,   _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  MICRO,    _______,  _______,  _______,  _______,  _______,  _______,  KC_APP,   _______,  KC_MSEL,  _______,  _______,  _______,  _______,
        TG(MOUSE_L),RGB_RMOD,RGB_VAD, RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  DM_PLY1,  DM_PLY2,  _______,            _______,                                ISS_MAN,  PAST_TB,  KEY_MJB,
        _______,            NK_TOGG,  _______,  _______,  _______,  _______,  EN_DASH,  EM_DASH,  DM_REC1,  DM_REC2,  DM_RSTP,            _______,            _______,            ISS_APP,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,TG(MOUSE_L),_______,  TO(NUM),  _______,  _______,  _______,  _______,            _______),
    [NUM] = LAYOUT_ansi_109(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MUTE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
        KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,                                KC_P4,    KC_P5,    KC_P6,
        KC_P1,              KC_P2,    KC_P3,    KC_PENT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,            KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        KC_P0,    KC_P0,    KC_PDOT,                                KC_PENT,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  TG(NUM),  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P0,              KC_PDOT),
    [MOUSE_L] = LAYOUT_ansi_109(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_WH_U,  KC_WH_L,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        TG(MOUSE_L),KC_BTN1,KC_BTN3,  KC_BTN2,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                                _______,  _______,  _______,
        _______,            _______,  KC_WH_D,  KC_WH_R,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            KC_MS_U,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,            _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [DVORAK] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [BASE]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FN]     = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [NUM]    = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MOUSE_L]= {ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

#    define CAPS_NUM_LOCK_MAX_BRIGHTNESS 0xFF
#    ifdef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#        undef CAPS_NUM_LOCK_MAX_BRIGHTNESS
#        define CAPS_NUM_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    endif

#    define CAPS_NUM_LOCK_VAL_STEP 8
#    ifdef RGB_MATRIX_VAL_STEP
#        undef CAPS_NUM_LOCK_VAL_STEP
#        define CAPS_NUM_LOCK_VAL_STEP RGB_MATRIX_VAL_STEP
#    endif

static uint8_t light_brightness_get(void) {
    uint8_t value = rgb_matrix_get_val();
    if (value < CAPS_NUM_LOCK_VAL_STEP) {
        value = CAPS_NUM_LOCK_VAL_STEP;
    } else if (value < (CAPS_NUM_LOCK_MAX_BRIGHTNESS - CAPS_NUM_LOCK_VAL_STEP)) {
        value += CAPS_NUM_LOCK_VAL_STEP; // one step more than current brightness
    } else {
        value = CAPS_NUM_LOCK_MAX_BRIGHTNESS;
    }

    return value;
}

static uint8_t CURR_POS = 0;

#define POS_AMT 5

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    if (layer >= FN) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                uint16_t kc = 0;

                if (index >= led_min && index < led_max && index != NO_LED &&
                        (kc = keymap_key_to_keycode(layer, (keypos_t){col,row})) > KC_TRNS) {
                    if (kc >= ISS_MAN)
                        rgb_matrix_set_color(index, RGB_WHITE);
                    else if (kc > 0xFF)
                        rgb_matrix_set_color(index, RGB_GREEN);
                    else
                        rgb_matrix_set_color(index, RGB_RED);
                }
            }
        }
    } else {
        uint8_t is_caps = host_keyboard_led_state().caps_lock;
        uint8_t is_cw = is_caps_word_on();

        uint8_t target = (is_cw ? 31 : (is_caps ? 30 : 0)) * POS_AMT;

        if (CURR_POS < target)
            CURR_POS ++;
        else if (CURR_POS > target)
            CURR_POS --;

        uint8_t pos = CURR_POS / POS_AMT;

#define TOP_LEN top_end - top_start + 1
#define MID_LEN mid_end - mid_start + 1
#define BOT_LEN bot_end - bot_start + 1

        int i;
        uint8_t v = light_brightness_get();

        uint8_t pos_top, pos_mid, pos_bot, top_start, top_end, mid_start, mid_end, bot_start, bot_end;

        if (layer == DVORAK) {
            // Highlight the escape key
            rgb_matrix_set_color(0, v, v, v);

            pos_top = pos <= 8 ? 0 : (pos - 8) / 3;
            pos_mid =                 pos      / 3;
            pos_bot = pos <= 4 ? 0 : (pos - 4) / 3;
            // pos_top = pos;
            // pos_mid = pos <= 7 ? 0 : pos - 7;
            // pos_bot = pos <= 17 ? 0 : pos - 17;

            // pyfgcrl
            top_start = 45;
            top_end = 51;
            // aoeuidhtns
            mid_start = 63;
            mid_end = 72;
            // qjkxbmwvz
            bot_start = 80;
            bot_end = 88;

            if (is_cw) {
                // _
                rgb_matrix_set_color(73, v, v, v);

                for (i = top_end; i > top_end - (pos_top > TOP_LEN ? TOP_LEN : pos_top); i --)
                    rgb_matrix_set_color(i, v, v, v);

                for (i = mid_end; i > mid_end - (pos_mid > MID_LEN ? MID_LEN : pos_mid); i --)
                    rgb_matrix_set_color(i, v, v, v);

                for (i = bot_end; i > bot_end - (pos_bot > BOT_LEN ? BOT_LEN : pos_bot); i --)
                    rgb_matrix_set_color(i, v, v, v);
            } else {
                for (i = top_start; i < top_start + (pos_top > TOP_LEN ? TOP_LEN : pos_top); i ++)
                    rgb_matrix_set_color(i, v, v, v);

                for (i = mid_start; i < mid_start + (pos_mid > MID_LEN ? MID_LEN : pos_mid); i ++)
                    rgb_matrix_set_color(i, v, v, v);

                for (i = bot_start; i < bot_start + (pos_bot > BOT_LEN ? BOT_LEN : pos_bot); i ++)
                    rgb_matrix_set_color(i, v, v, v);
            }
        } else {
            pos_top = pos / 3;
            pos_mid = pos == 0 ? 0 : (pos - 1) / 3;
            pos_bot = pos <= 1 ? 0 : (pos - 2) / 3;
            // pos_top = pos;
            // pos_mid = pos <= 10 ? 0 : pos - 10;
            // pos_bot = pos <= 19 ? 0 : pos - 19;

            // qwertyuiop
            top_start = 42;
            top_end = 51;
            // asdfghjkl
            mid_start = 63;
            mid_end = 71;
            // zxcvbnm
            bot_start = 79;
            bot_end = 85;

            if (is_cw) {
                // _
                rgb_matrix_set_color(31, v, v, v);

                for (i = top_end; i > top_end - (pos_top > TOP_LEN ? TOP_LEN : pos_top); i --)
                    rgb_matrix_set_color(i, v, v, v);

                for (i = mid_end; i > mid_end - (pos_mid > MID_LEN ? MID_LEN : pos_mid); i --)
                    rgb_matrix_set_color(i, v, v, v);

                for (i = bot_end; i > bot_end - (pos_bot > BOT_LEN ? BOT_LEN : pos_bot); i --)
                    rgb_matrix_set_color(i, v, v, v);
            } else {
                for (i = top_start; i < top_start + (pos_top > TOP_LEN ? TOP_LEN : pos_top); i ++)
                    rgb_matrix_set_color(i, v, v, v);

                for (i = mid_start; i < mid_start + (pos_mid > MID_LEN ? MID_LEN : pos_mid); i ++)
                    rgb_matrix_set_color(i, v, v, v);

                for (i = bot_start; i < bot_start + (pos_bot > BOT_LEN ? BOT_LEN : pos_bot); i ++)
                    rgb_matrix_set_color(i, v, v, v);
            }
        }
#undef TOP_LEN
#undef MID_LEN
#undef BOT_LEN
    }
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        // active == set to windows
        // layer 0: dvorak
        // layer 1: windows
        default_layer_set(1UL << (active ? 1 : 0));
        return false; // Prevent the next level from changing it
    }
    return true;
}
