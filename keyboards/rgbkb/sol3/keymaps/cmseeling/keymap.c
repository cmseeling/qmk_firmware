/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/cmseeling> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ ESC  │   1  │   2  │   3  │   4  │   5  │  F1  │  │   =  │   6  │   7  │   8  │   9  │   0  │  Del │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │  F5  │  │   -  │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Sft^ │   A  │   S  │   D  │   F  │   G  │  F6  │  │ oled │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├ oled ┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │   Z  │   X  │   C  │   V  │   B  │  F12 │  │ oled │   N  │   M  │   ,  │   .  │   /  │Shift │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │  Win │ Alt^ │   [  │   ]  │      │  End │  │   `  │      │ Left │ Down │ Up   │Right │Layer^│
 * └──────┴──────┴──────┴──────┴──────┤ Space├──────┤  ├──────┤ Enter├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │ Home^│  │ BkSp │      │
 *                                    └──────┴──────┘  └──────┴──────┘
 */
 /* FKey
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  │  F7  │  F8  │  F9  │  F10 │  F11 │  F12 │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │  Up  │      │ PgUp │      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Left │ Down │Right │ PgDn │      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Home │      │  End │      │      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │PntScn│      │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────│      ├──────┤  ├──────┤      ├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │      │  │      │      │
 *                                    └──────┴──────┘  └──────┴──────┘
 */
 /* RGB
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  │  F7  │  F8  │  F9  │  F10 │  F11 │  F12 │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ SatDn│BrtUp │ SatUp│ Boot │      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ HueDn│BrtDn │ HueUp│RgbRst│      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ SpdDn│      │ SpdUp│      │      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ MPrev│Toggle│ MNext│      │      │      │  │      │      │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────│      ├──────┤  ├──────┤      ├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │      │  │      │      │
 *                                    └──────┴──────┘  └──────┴──────┘
 */

enum sol_layers {
    _QWERTY,
    _FN,
    _ADJUST
};

enum sol_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap Dance Enums
enum {
    TD_ALT,
    TD_CAPS,
    TD_HOME,
    TD_LAYR,
};

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void td_alt_finished(tap_dance_state_t *state, void *user_data);
void td_alt_reset(tap_dance_state_t *state, void *user_data);
void td_layr_finished(tap_dance_state_t *state, void *user_data);

#define FN       MO(_FN)
#define ADJUST   MO(_ADJUST)
#define QWERTY   DF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_ESC,      KC_1,    KC_2,       KC_3,    KC_4,    KC_5,    KC_F1,                        KC_EQL,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,      KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_F5,                        KC_MINS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        TD(TD_CAPS), KC_A,    KC_S,       KC_D,    KC_F,    KC_G,    KC_F6,                        KC_MINS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,     KC_Z,    KC_X,       KC_C,    KC_V,    KC_B,    KC_F12,                       KC_EQL,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,     KC_LGUI, TD(TD_ALT), KC_LBRC, KC_RBRC, KC_SPC,  KC_END, TD(TD_HOME), KC_BSPC, KC_GRAVE, KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TD(TD_LAYR),

        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                       KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
    ),

    [_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, _______, KC_UP,   _______, KC_PGUP, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, KC_HOME, _______, KC_END,  _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, RM_SATD, RM_VALU, RM_SATU, QK_BOOT, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, RM_HUED, RM_VALD, RM_HUEU, RGB_RST, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, RM_SPDD, _______, RM_SPDU, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, RM_PREV, RM_TOGG, RM_NEXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (layer_state_is(_FN)) {
        rgb_matrix_set_color_all(RGB_GREEN);
    } else if (layer_state_is(_ADJUST)) {
        rgb_matrix_set_color_all(RGB_PURPLE);
    } else {
        rgb_matrix_set_color_all(RGB_BLUE);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case MENU_BTN:
            if (record->event.pressed) {
                rgb_menu_selection();
            }
            return false;
        case MENU_UP:
            if (record->event.pressed) {
                rgb_menu_action(true);
            }
            return false;
        case MENU_DN:
            if (record->event.pressed) {
                rgb_menu_action(false);
            }
            return false;
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;
        case TCH_TOG:
            if (record->event.pressed) {
                touch_encoder_toggle();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;
    }
}

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void td_alt_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_LALT);
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_LALT);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_FN)) {
                // If already set, then switch it off
                layer_off(_FN);
            } else {
                // If not already set, then switch the layer on
                layer_on(_FN);
            }
            break;
        default:
            break;
    }
}

void td_alt_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_LALT);
}

void td_layr_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_HOLD:
        case TD_SINGLE_TAP:
            layer_move(0);
            break;
        case TD_DOUBLE_TAP:
            if (!layer_state_is(_ADJUST)) {
                layer_on(_ADJUST);
            }
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_alt_finished, td_alt_reset),
    [TD_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_ESC),
    [TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_LAYR] = ACTION_TAP_DANCE_FN(td_layr_finished),
};

void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWRTY"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("FN   "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

static void render_cat(void) {
    static const char PROGMEM sleepy_cat[] = {
        // 'sleepy_cat', 32x32px
        0x00, 0x00, 0x00, 0x04, 0x84, 0x54, 0x24, 0x54, 0x0c, 0x04, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x80, 0x44, 0x24, 0xc6, 0x85, 
        0x84, 0x80, 0xe0, 0x20, 0x10, 0x08, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xe0, 0x10, 0x0c, 0x02, 0x02, 0x01, 0x7d, 0x83, 0x00, 0x80, 0x80, 0x80, 0x01, 
        0x02, 0x03, 0x00, 0x00, 0x00, 0x80, 0x41, 0x02, 0xfd, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x07, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x33, 0x24, 0x28, 0x28, 0x28, 0x29, 
        0x29, 0x3a, 0x18, 0x1c, 0x39, 0x24, 0x24, 0x3a, 0x2d, 0x26, 0x31, 0x1f, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(sleepy_cat, sizeof(sleepy_cat));
}

void render_lock_status(void)
{
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(  led_state.caps_lock ? PSTR("Caps ") : PSTR("     "), false);
    oled_write_ln_P(   led_state.num_lock ? PSTR("Nmlck") : PSTR("     "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("Scrol") : PSTR("     "), false);
}

bool oled_task_user(void) {
    oled_clear();
    render_icon();
    oled_write_ln_P(PSTR("     "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            // oled_write_ln_P(PSTR("Qwrty"), false);
            // render_lock_status();
            oled_write_ln_P(PSTR("     "), false);
            render_cat();
            break;
        case _FN:
            // oled_write_ln_P(PSTR("FNKEY"), false);
            // render_lock_status();
            oled_write_ln_P(PSTR("     "), false);
            render_cat();
            break;
        case _ADJUST:
            render_rgb_menu();
            break;
    }
    return false;
}
