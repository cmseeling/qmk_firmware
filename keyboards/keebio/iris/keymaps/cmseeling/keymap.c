#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _SYMBOL 1
#define _NAVIGATION 2
#define _ENCODER 3
#define _RGB 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMBOL
};

enum {
  TD_GRV = 0,
  TD_CTRL,
  TD_ALT,
  TD_SLCK,
  TD_ESC
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  TRIPLE_TAP = 4,
  NO_TAP_STATE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
    TD(TD_ESC),   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                  KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    KC_DEL,
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
      KC_TAB,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                  KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,    KC_BSLS,
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
      KC_LSFT,    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                                  KC_H,      KC_J,      KC_K,      KC_L,     KC_SCLN,  KC_QUOT,
  //----------+----------+----------+----------+----------+----------+----------+      ----------+----------+----------+----------+----------+----------+----------+
      KC_LGUI,    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,  TG(_ENCODER),     TD(TD_GRV),   KC_N,      KC_M,    KC_COMM,    KC_DOT,    KC_SLSH, TG(_SYMBOL),
  //----------+----------+----------+----------+----------+----------+----------+      ----------+----------+----------+----------+----------+----------+----------+
                                          TD(TD_CTRL), KC_SPC,  TD(TD_ALT),                   KC_BSPC,   KC_ENT,   TD(TD_SLCK)
  //                                      \----------+----------+----------/                \----------+----------+----------/
  ),

  [_SYMBOL] = LAYOUT(
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
      KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,                                  KC_F7,     KC_F8,     KC_F9,    KC_F10,    KC_F11,    KC_F12,
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
     _______,   _______,   _______,   _______,   _______,   _______,                               KC_EQL,    KC_AMPR,   KC_PIPE,   KC_EXLM,   _______,   _______,
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
     _______,   _______,   _______,   _______,   _______,   _______,                               KC_SLSH,   KC_LBRC,   KC_RBRC,   KC_BSLS,   _______,   _______,
  //----------+----------+----------+----------+----------+----------+----------+      ----------+----------+----------+----------+----------+----------+----------+
     _______,   _______,   _______,   _______,   _______,   _______,   _______,         _______,   _______,   _______,   _______,   _______,   _______,   _______,
  //----------+----------+----------+----------+----------+----------+----------+      ----------+----------+----------+----------+----------+----------+----------+
                                            _______,   _______,   _______,                    _______,   _______,   _______
  //                                      \----------+----------+----------/                \----------+----------+----------/
  ),

  [_NAVIGATION] = LAYOUT(
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
     _______,   _______,   _______,    KC_F4,      KC_F5,     KC_F6,                               _______,     KC_7,      KC_8,      KC_9,    KC_SLSH,   KC_EQL,
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
     _______,   _______,    KC_UP,    _______,   KC_PGUP,   KC_HOME,                               _______,     KC_4,      KC_5,      KC_6,    KC_ASTR,   _______,
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
     _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_PGDN,   KC_END,                                _______,     KC_1,      KC_2,      KC_3,    KC_PLUS,   _______,
  //----------+----------+----------+----------+----------+----------+----------+      ----------+----------+----------+----------+----------+----------+----------+
     _______,   _______,   _______,   _______,   _______,   _______,   _______,         _______,   _______,     KC_0,     KC_DOT,   _______,   KC_MINS,   _______,
  //----------+----------+----------+----------+----------+----------+----------+      ----------+----------+----------+----------+----------+----------+----------+
                                            _______,   _______,   _______,                    _______,   _______,   _______
  //                                      \----------+----------+----------/                \----------+----------+----------/
  ),

  [_ENCODER] = LAYOUT(
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
     _______,   _______,   _______,   _______,   _______,   _______,                               _______,   _______,   _______,   _______,   _______,   _______,
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
     _______,   _______,   _______,   _______,   _______,   _______,                               _______,   _______,   _______,   _______,   _______,   _______,
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
     _______,   _______,   _______,   _______,   _______,   _______,                               _______,   _______,   _______,   _______,   _______,   _______,
  //----------+----------+----------+----------+----------+----------+----------+      ----------+----------+----------+----------+----------+----------+----------+
     _______,   _______,   _______,   _______,   _______,   _______,   _______,         _______,   _______,   _______,   _______,   _______,   _______,   _______,
  //----------+----------+----------+----------+----------+----------+----------+      ----------+----------+----------+----------+----------+----------+----------+
                                            _______,   _______,   _______,                    _______,   _______,   _______
  //                                      \----------+----------+----------/                \----------+----------+----------/
  ),

  [_RGB] = LAYOUT(
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
     RGB_TOG,   BL_STEP,   _______,   _______,   _______,   _______,                               _______,   _______,   _______,   _______,   _______,   _______,
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
     RGB_MOD,   _______,   _______,   _______,   _______,   _______,                               _______,   _______,   _______,   _______,   _______,   _______,
  //----------+----------+----------+----------+----------+----------+                            ----------+----------+----------+----------+----------+----------+
     RGB_HUI,   RGB_SAI,   RGB_VAI,   _______,   _______,   _______,                               _______,   _______,   _______,   _______,   _______,   _______,
  //----------+----------+----------+----------+----------+----------+----------+      ----------+----------+----------+----------+----------+----------+----------+
     RGB_HUD,   RGB_SAD,   RGB_VAD,   _______,   _______,   _______,   _______,         _______,   _______,   _______,   _______,   _______,   _______,   _______,
  //----------+----------+----------+----------+----------+----------+----------+      ----------+----------+----------+----------+----------+----------+----------+
                                            _______,   _______,   _______,                    _______,   _______,   _______
  //                                      \----------+----------+----------/                \----------+----------+----------/
  ),
};

//Determine the current tap dance state
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    return DOUBLE_TAP;
  } else if (state->count == 3) {
    return TRIPLE_TAP;
  }

  return NO_TAP_STATE;
}

//Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
  .is_press_action = true,
  .state = 0
};

void grv_tap (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    //send ` to the computer unless we're on the RGB layer. Turn off RGB layer if it's active
    if (layer_state_is(_RGB)) {
      layer_off(_RGB);
    } else {
      tap_code(KC_GRV);
    }
  } else if (state->count == 2) {
    if (layer_state_is(_NAVIGATION)) {
      //if already set, then switch it off
      layer_off(_NAVIGATION);
    } else {
      //if not already set, then switch the layer on
      layer_on(_NAVIGATION);
    }
  } else if (state->count == 4) {
    //I've confused myself and need to reset the layers
    if (layer_state_is(_SYMBOL))
        layer_off(_SYMBOL);

    if (layer_state_is(_NAVIGATION))
        layer_off(_NAVIGATION);

    if (layer_state_is(_ENCODER))
        layer_off(_ENCODER);
  } else if (state->count == 7) {
    //Activate RGB layer
    layer_on(_RGB);
  }
}

void ctrl_dance_finish (qk_tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_LCTRL);
      break;
    case SINGLE_HOLD:
      register_code(KC_LCTRL);
      break;
    case DOUBLE_TAP:
      register_code(KC_LSFT);
      tap_code(KC_LBRC);
      unregister_code(KC_LSFT);
      break;
    case TRIPLE_TAP:
      tap_code(KC_LBRC);
      break;
  }
}

void ctrl_dance_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code (KC_LCTRL);
  ql_tap_state.state = 0;
}

void alt_dance_finish (qk_tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_LALT);
      break;
    case SINGLE_HOLD:
      register_code(KC_LALT);
      break;
    case DOUBLE_TAP:
      register_code(KC_LSFT);
      tap_code(KC_RBRC);
      unregister_code(KC_LSFT);
      break;
    case TRIPLE_TAP:
      tap_code(KC_RBRC);
      break;
  }
}

void alt_dance_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code (KC_LALT);
  ql_tap_state.state = 0;
}

void esc_tap (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 3) {
    tap_code(KC_ESC);
  } else {
    register_code (KC_LCTL);   register_code (KC_LALT);   register_code (KC_DEL);
  }
}

void esc_dance_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 3) {
    unregister_code (KC_LCTL); unregister_code (KC_LALT); unregister_code (KC_DEL);
  }
}

//test if shift + double tap will send shifted code
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_GRV]  = ACTION_TAP_DANCE_FN(grv_tap),
  [TD_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_dance_finish, ctrl_dance_reset),
  [TD_ALT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_dance_finish, alt_dance_reset),
  [TD_SLCK] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
  [TD_ESC]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_tap, esc_dance_reset),
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == _ENCODER) {
    uint8_t mods = get_mods();
    clear_mods();
    if (mods == MOD_BIT(KC_RSFT)) {
      if (clockwise) {
        tap_code(KC_RGHT);
      } else {
        tap_code(KC_LEFT);
      }
    } else {
      if (clockwise) {
        tap_code(KC_DOWN);
      } else {
        tap_code(KC_UP);
      }
    }
    set_mods(mods);
  } else {
    if (clockwise) {
      tap_code(KC_WH_D);
    } else {
      tap_code(KC_WH_U);
    }
  }
}
