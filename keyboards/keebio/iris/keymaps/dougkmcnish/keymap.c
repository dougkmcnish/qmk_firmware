#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define KC_CESC LCTL_T(KC_ESC)
#define KC_RAIS MO(2)
#define KC_LOWR MO(1)
#define KC_AJST MO(3)
#define KC_TNEX LSG(KC_RBRC)
#define KC_TPRE LSG(KC_LBRC)
#define KC_CLRT LCTL(KC_RGHT)
#define KC_CLLT LCTL(KC_LEFT)



enum custom_keycodes {
    RGPULS = SAFE_RANGE,
    RGCYCLE,
    RGSOLID,
    EMORGF,
    EMORGD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CESC, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_AJST,           KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LOWR, KC_BSPC,                    KC_SPC, KC_RAIS,  KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_CLLT, KC_CLRT, KC_TPRE,                            KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, _______,  KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, KC_TNEX, _______,            KC_F2, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, KC_AJST,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______,  RGPULS, RGSOLID, RGCYCLE, _______, _______,                            _______,  TG(2),  KC_EQL,  KC_SLSH, KC_ASTR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______,  KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_LALT, KC_LEFT, KC_RGHT,   KC_UP, _______,                            _______,  KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR,  KC_P1,   KC_P2,   KC_P3,   KC_DOT,  KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_AJST,  KC_DEL,                    KC_DEL, _______,   KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),



  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_VOLU, KC_ASTR, KC_LPRN, KC_RPRN,  QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT,  EMORGD,  EMORGF, KC_UNDS,                            KC_EQL,  KC_VOLD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, _______,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD,  TG(2),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {


    case EMORGF:
      if (record->event.pressed) {
	SEND_STRING(SS_LCTL("c") SS_LCTL(">"));
      } else {
	//pass
      }
      break; 

    case EMORGD:
      if (record->event.pressed) {
	SEND_STRING(SS_LCTL("c") SS_LCTL("<"));
      } else {
	//pass
      }
      break; 
      
    case RGPULS:
      if (record->event.pressed) {
	rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_WIDE);
      } else {
	//Nothing to see here
      }
      break;

    case RGCYCLE:
      if (record->event.pressed) {
	rgb_matrix_mode(RGB_MATRIX_CYCLE_ALL);
      } else {
	//Nothing to see here
      }
      break;

    case RGSOLID:
      if (record->event.pressed) {
	rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
      } else {
	//Nothing to see here
      }
      break;
    }
    return true;
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (layer_state_is(0)) {
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
        } else if (layer_state_is(1)) {
            if (clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    }
    return false;
}
