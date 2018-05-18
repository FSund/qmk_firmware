#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5
#define _NUMPAD 6
#define _ALTGR 7

enum custom_keycodes {
  LOWER,
  RAISE,
  ADJUST
};

#define NUMPAD MO(_NUMPAD)
#define ALTGR MO(_ALTGR)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// use S() to produce shifted versions of keys
// #define S(kc) LSFT(kc) // already defined

// alt gr
#define G(kc) RALT(kc)

// custom keycodes
// use F_ prefix to avoid problems

// NB! I use Norwegian keyboard layout on my machines, so the keymap probably
// doesn't make much sense for US/ANSI users

#define F_FSLH S(KC_7) // forward slash
#define F_BSLH KC_EQL // backward slash
#define F_EQL S(KC_0) // equals sign
#define F_APOS KC_BSLS // '
#define F_TIMES S(KC_BSLS) // *
#define F_PLUS KC_MINS // +
#define F_QUEST S(KC_MINS) // ?
#define F_HAT S(KC_RBRC) // ^
#define F_TILD G(KC_RBRC) // ~
#define F_UML KC_RBRC // ¨ (umlaut)
#define F_SECT S(KC_GRV) // section sign ("law sign") (shifted key below esc)


#define KC_AA KC_LBRC
#define KC_OE KC_SCLN
#define KC_AE KC_QUOT

// brackets
#define F_SBRL G(KC_8) // square bracket left
#define F_SBRR G(KC_9) // square bracket right
#define F_CBRL G(KC_7) // curly bracket left
#define F_CBRR G(KC_0) // curly bracket right
#define F_RBRL S(KC_8) // round bracket left
#define F_RBRR S(KC_9) // round bracket right
#define F_ABRL KC_NUBS // angle bracket left
#define F_ABRR S(KC_NUBS) // angle bracket right

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    F_FSLH,  F_APOS,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, \
  KC_LCTL, KC_LGUI, NUMPAD,  KC_LALT, LOWER,   KC_SPC,      KC_SPC,  RAISE,   ALTGR,   KC_RGUI, KC_RCTL, KC_ENT   \
),

[_LOWER] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_GRV,  _______, _______, _______, _______, _______,     F_BSLH,  F_FSLH,  F_SBRL,  F_SBRR,  F_EQL,   KC_DEL,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       F_ABRL,  F_ABRR,  F_RBRL,  F_RBRR,  F_TIMES, F_TILD,  \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,      KC_F11,  KC_F12,  F_CBRL,  F_CBRR,  F_PLUS,  _______, \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______  \
),

[_RAISE] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  F_SECT,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),     F_QUEST, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, F_UML,   \
  _______, S(KC_6), G(KC_2), G(KC_3), G(KC_4), G(KC_5),     F_HAT,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______  \
),

[_ADJUST] =  LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, KC_AA,   _______, _______, _______,     _______, _______, _______, _______, KC_PSCR, _______, \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_OE,   _______, _______, \
  _______, KC_AE,   _______, _______, _______, _______,     _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______  \
),


// ,-------------------.
// | NL | /  | *  | -  |
// |----|----|----|----|
// | 7  | 8  | 9  | +  |
// |----|----|----|----|
// | 4  | 5  | 6  | +  |
// |----|----|----|----|
// | 1  | 2  | 3  | En |
// |----|----|----|----|
// | 0  | 0  | .  | En |
// `-------------------'

[_NUMPAD] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______,     _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
  _______, _______, _______, _______, _______, _______,     _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
  _______, _______, _______, _______, _______, _______,     _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
  _______, _______, _______, _______, _______, _______,     _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
  _______, _______, _______, _______, _______, _______,     _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PENT  \
),

[_ALTGR] =  LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, KC_AA,   _______, _______, _______,     _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_OE,   _______, _______, \
  _______, KC_AE,   _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______  \
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
