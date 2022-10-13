// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include  "g/keymap_combo.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum ferris_tap_dances {
  TD_Q_ESC
};

//#define KC_CTSC RCTL_T(KC_SCLN)
//#define KC_CTLA LCTL_T(KC_A)
//#define KC_LSHZ LSFT_T(KC_Z)
//#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_LOWBS LT(1, KC_BSPC)
#define KC_RAISP LT(2, KC_SPC)
#define KC_CLGV CTL_T(KC_GRV)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_LALT OSM(MOD_LALT)
#define OSL_AJST OSL(3)
#define AJST_TOG TG(3)
#define LOW_TOG  TG(1)
#define RAI_TOG  TG(2)

/*
COMB(combo_lq_ent,        KC_ENT,        KC_L, KC_QUOT)
COMB(combo_as_tab,         KC_TAB,       KC_A, KC_S)
COMB(combo_qw_esc,         KC_ESC,       KC_Q, KC_W)
COMB(combo_zx_shift,       KC_LSFT,      KC_Z, KC_X)
COMB(combo_dotslash_shift, KC_RSFT,      KC_DOT, KC_SLSH)
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,           KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,     KC_G,           KC_H,    KC_J,     KC_K,    KC_L, KC_QUOT,
    KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,           KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH,
                            KC_LGUI, KC_LOWBS,       KC_RAISP, KC_CLGV
  ),

  [_LOWER] = LAYOUT( /* [> LOWER <] */
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    _______, _______, KC_BTN2, KC_BTN1, KC_PGUP,         KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_SCLN,
    _______, _______, _______, LOW_TOG, KC_PGDN,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TILD,
                               _______, _______,         _______, _______
  ),

  [_RAISE] = LAYOUT( /* [> RAISE <] */
    KC_EXLM,    KC_AT,  KC_HASH,  KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,
    KC_CAPS, OSM_LALT, OSM_LGUI, _______, OSL_AJST,       KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______,  _______,  _______, LOW_TOG, AJST_TOG,       KC_UNDS, KC_PLUS,  _______, _______,   RESET,
                                 _______,  _______,       _______, _______
  ),

  [_ADJUST] = LAYOUT( /* [> ADJUST <] */
      KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,           KC_PLUS,  KC_P7,   KC_P8,   KC_P9,  KC_PAST,
      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,           KC_MINS,  KC_P4,   KC_P5,   KC_P6,  KC_PSLS,
     KC_F11,  KC_F12, _______, _______, AJST_TOG,            KC_DOT,  KC_P1,   KC_P2,   KC_P3,  KC_PENT,
                                _______, _______,           _______,  KC_P0
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
