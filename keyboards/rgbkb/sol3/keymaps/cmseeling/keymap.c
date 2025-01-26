/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/cmseeling> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. Chris Seeling
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
 * │ Ctrl │  Win │ Alt^ │   [  │   ]  │      │  End │  │   `  │      │ Left │ Down │ Up   │Right │Layer^|
 * └──────┴──────┴──────┴──────┴──────┤ Space├──────┤  ├──────┤ Enter├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │ Home^│  │ BkSp │      │
 *                                    └──────┴──────┘  └──────┴──────┘
 */

 /* FKey
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  │  F7  │  F8  │  F9  │  F10 │  F11 │  F12 │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │Layerv│  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │      │      │      │      │      │      │      |
 * └──────┴──────┴──────┴──────┴──────│      ├──────┤  ├──────│      ├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │      │  │      │      │
 *                                    └──────┴──────┘  └──────┴──────┘
 */

 /* RGB
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │      │  │ BrtUp│Static│Breath│Rainbo│ Swirl│      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │ BrtDn│      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │ SatUp│ SatDn│      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │ HueUp│  │ SpdUp│      │      │      │      │      │      |
 * └──────┴──────┴──────┴──────┴──────│      ├──────┤  ├──────│ Mode ├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │ HueDn│  │ SpdDn│      │
 *                                    └──────┴──────┘  └──────┴──────┘
 */

typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_SINGLE_TAP
} td_state_t;

enum td_keycodes {
    TD_ALT,
    TD_SHFT,
    TD_LAYR,
    TD_HOME,
    LYRDWN
};

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Function to determine the current tapdance state
uint8_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void TD_ALT_finished(tap_dance_state_t *state, void *user_data);
void TD_ALT_reset(tap_dance_state_t *state, void *user_data);
void TD_SHFT_finished(tap_dance_state_t *state, void *user_data);
void TD_SHFT_reset(tap_dance_state_t *state, void *user_data);
void TD_LAYR_finished(tap_dance_state_t *state, void *user_data);

enum sol_layers {
    _QWERTY,
    _FKEY,
    _RGB
};

#define BASE MO(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_ESC,      KC_1,    KC_2,       KC_3,    KC_4,    KC_5,    KC_F1,                        KC_EQL,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,      KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_F5,                        KC_MINS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        TD(TD_SHFT), KC_A,    KC_S,       KC_D,    KC_F,    KC_G,    KC_F6,                        KC_MINS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,     KC_Z,    KC_X,       KC_C,    KC_V,    KC_B,    KC_F12,                       KC_EQL,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,     KC_LGUI, TD(TD_ALT), KC_LBRC, KC_RBRC, KC_SPC,  KC_END, TD(TD_HOME), KC_BSPC, KC_GRAVE, KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TD(TD_LAYR),

        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                       KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
    ),

    [_FKEY] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_RGB] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                   RGB_VAI, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, _______, RGB_TOG,
        _______, _______, _______, _______, _______, _______, _______,                   RGB_VAD, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, RGB_SAI, RGB_SAD, _______, _______,                   _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_HUD, RGB_SPD, RGB_SPI, RGB_MOD, _______, _______, _______,  _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case LYRDWN:
            if (record->event.pressed) {
                layer_off(_FKEY);
                rgblight_sethsv_noeeprom(160, 255, 255);
            } else {
                layer_on(_FKEY);
                rgblight_sethsv_noeeprom(80, 255, 255);
            }
            return false; // Skip all further processing of this key
        default:
            return true;
    }
}

// Determine the tapdance state to return
uint8_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }

    if (state->count == 2) return DOUBLE_SINGLE_TAP;

    else return 100; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

/*
    Double tap to go to FKEY layer, otherwise send ALT
*/
void TD_ALT_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            tap_code(KC_LALT);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case DOUBLE_SINGLE_TAP:
            if (layer_state_is(_FKEY)) {
                //if already set, then switch it off
                layer_off(_FKEY);
                rgblight_sethsv_noeeprom(160, 255, 255);
            } else {
                //if not already set, then switch the layer on
                layer_on(_FKEY);
                rgblight_sethsv_noeeprom(80, 255, 255);
            }
            break;
    }
}

void TD_ALT_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code (KC_LALT);
}

/*
    Double tap to send ESC, otherwise send HOME
*/
void TD_HOME_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            tap_code(KC_HOME);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_ESC);
            break;
    }
}

/*
    Double tap to send CAPSLOCK, otherwise, send shift
*/
void TD_SHFT_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    led_t led_state = host_keyboard_led_state();
    switch (td_state) {
        case SINGLE_TAP:
            tap_code(KC_LSFT);
            break;
        case SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_CAPS);
            led_state.caps_lock ? rgblight_increase_hue_noeeprom() : rgblight_decrease_hue_noeeprom();
            break;
    }
}

void TD_SHFT_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code (KC_LSFT);
}

/*
    RGB Layer switch and layer escape key. On single press reset all layers. On double tap, go to RGB layer.
    When activating RGB, increase hue by 2. On reset (if RGB was active), reset hue.
*/
void TD_LAYR_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            rgblight_sethsv_noeeprom(160, 255, 255);
            layer_move(0);
            break;
        case DOUBLE_SINGLE_TAP:
            if (!layer_state_is(_RGB)) {
                rgblight_sethsv_noeeprom(0, 255, 255);
            }
            layer_on(_RGB);
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [TD_ALT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_ALT_finished, TD_ALT_reset),
    [TD_HOME] = ACTION_TAP_DANCE_FN(TD_HOME_finished),
    [TD_SHFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_SHFT_finished, TD_SHFT_reset),
    [TD_LAYR] = ACTION_TAP_DANCE_FN(TD_LAYR_finished)
};

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
            oled_write_ln_P(PSTR("Qwrty"), false);
            render_lock_status();
            oled_write_ln_P(PSTR("     "), false);
            render_cat();
            break;
        case _FKEY:
            oled_write_ln_P(PSTR("FNKEY"), false);
            render_lock_status();
            oled_write_ln_P(PSTR("     "), false);
            render_cat();
            break;
        case _RGB:
            render_rgb_menu();
            break;
    }

    return false;
}
