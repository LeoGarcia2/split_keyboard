#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _CODE 1
#define _ACCENT 2

enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  CODE,
  ACCENT
};

#define CODING MO(_CODE)
#define ACCENTING MO(_ACCENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT] = LAYOUT_ortho_4x12(
    KC_Q, KC_W, KC_E, LT(_ACCENT, KC_R), LT(_CODE, KC_T), KC_ESC,                               KC_P, KC_O, KC_I, LT(_ACCENT, KC_U), LT(_CODE, KC_Y), KC_ENT, \
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_SPC,                       LGUI_T(KC_SCLN), LALT_T(KC_L), LCTL_T(KC_K), LSFT_T(KC_J), KC_H, KC_BSPC, \
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TAB,                                                       KC_SLSH, KC_DOT, KC_COMM, KC_M, KC_N, KC_DEL, \
    _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______, _______ \
  ),

  [_CODE] = LAYOUT_ortho_4x12( \
    RALT(KC_3), RALT(KC_7), KC_4, KC_3, _______, KC_ESC,                                         KC_BSLS, S(KC_EQL), RALT(KC_MINS), RALT(KC_5), _______, KC_ENT, \
    KC_RBRC, KC_8, KC_NUBS, S(KC_NUBS), _______, KC_SPC,                                S(KC_QUOT), KC_6, KC_MINS, KC_5, _______, KC_BSPC, \
    RALT(KC_6), RALT(KC_8), RALT(KC_0), KC_1, _______, KC_TAB,                                  RALT(KC_2), KC_EQL, RALT(KC_EQL), RALT(KC_4), _______, KC_DEL, \
    _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______,  _______, _______ \
  ),
  

  [_ACCENT] = LAYOUT_ortho_4x12( \
    _______, KC_UP, _______, KC_2, KC_7, KC_ESC,                                                LALT_T(S(KC_3)), LCTL_T(S(KC_2)), LSFT_T(S(KC_1)), _______, _______, KC_ENT, \
    KC_LEFT, KC_DOWN, KC_RIGHT, KC_9, KC_0, KC_SPC,                                             S(KC_6), S(KC_5), S(KC_4), KC_CAPS, _______, KC_BSPC, \
    C(KC_C), C(KC_V), S(KC_LBRC), KC_LBRC, KC_QUOT, KC_TAB,                                     S(KC_9), S(KC_8), S(KC_7), S(KC_0), _______, KC_DEL, \
    _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______, _______ \
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DEFAULT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DEFAULT);
      }
      return false;
    case CODE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CODE);
      }
      return false;
    case ACCENT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ACCENT);
      }
      return false;
  }
  return true;
}
