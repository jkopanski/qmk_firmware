#include "clueboard.h"

// Helpful defines
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define _______ KC_TRNS

#define _I 1

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL  0
#define _PDB 1
#define _PDS 2
#define _FL  3
#define _CL  4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = KEYMAP(
  F(0),    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_LBRC,  KC_RBRC,   KC_GRV,  KC_BSPC,          KC_HOME, \
  KC_TAB,  KC_SCLN,    KC_COMM,   KC_DOT,   KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,    KC_L,     KC_SLSH,  KC_EQL,  KC_BSLS,                   KC_END, \
  KC_CAPS, KC_A,    KC_O,   KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,    KC_S,  KC_MINS,  KC_NUHS,  KC_ENT,                             \
  KC_LSFT, KC_NUBS, KC_QUOT,   KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W, KC_V,   KC_Z,  KC_RO,    KC_RSFT,          KC_UP,            \
  KC_LCTL, KC_LGUI, KC_LALT, KC_MHEN,          KC_SPC,KC_SPC,                        KC_HENK,  KC_RALT,  KC_RCTL,  MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer
   */
[_FL] = KEYMAP(
  KC_GRV,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______, KC_DEL,           BL_STEP, \
  _______, _______, _______,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK, KC_PAUS,  _______,  _______,  _______,                   _______, \
  _______, _______, MO(_CL),_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                           \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,          KC_PGUP,         \
  _______, _______, _______, _______,        _______,_______,                        _______,  _______,  MO(_CL),  MO(_FL), KC_HOME, KC_PGDN, KC_END),

  /* Keymap _CL: Control layer
   */
[_CL] = KEYMAP(
  TO(0), TO(1), TO(2),TO(3),TO(4),_______,_______,_______,_______,_______, _______,  _______,  _______,  _______, RGB_TOG,             RGB_VAI, \
  TG(_PDB), _______, _______,_______,RESET,  _______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                   RGB_VAD, \
  _______, _______, MO(_CL),_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                         \
  MO(_FL), _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  MO(_FL),          RGB_SAI,          \
  _______, _______, _______,_______,        RGB_MOD,   RGB_MOD,                            _______,  _______,  MO(_CL),  _______, RGB_HUD,    RGB_SAD,    RGB_HUI),


/* Keymap _PDB: Programmer Dvorak base layer
*/
[_PDB] = KEYMAP(
  M(0),  M(1), KC_LBRC,   M(3), M(4), M(5),   KC_EQL,   M(7),   M(8),   M(9),    KC_RBRC,     M(11),  M(12),   _______,  KC_BSPC,          KC_HOME, \
  KC_TAB,  KC_SCLN, KC_COMM,   KC_DOT,  KC_P,    KC_Y,      KC_F,     KC_G,      KC_C,      KC_R,       KC_L,        KC_SLSH,  M(25),  KC_BSLS,                   KC_END, \
  KC_CAPS, KC_A,    KC_O,      KC_E,    KC_U,    KC_I,      KC_D,     KC_H,      KC_T,      KC_N,       KC_S,        KC_MINS,  KC_NUHS,  KC_ENT,                             \
  M(23), KC_NUBS, KC_QUOT,   KC_Q,    KC_J,    KC_K,      KC_X,     KC_B,      KC_M,      KC_W,       KC_V,        KC_Z,  KC_RO,    M(23),          KC_UP,            \
  KC_LCTL, KC_LGUI, KC_LALT, KC_MHEN,          KC_SPC,KC_SPC,                        KC_HENK,  KC_RALT,  KC_RCTL,  MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT),

/* Keymap _PDB: Programmer Dvorak base layer
*/
[_PDS] = KEYMAP(
  M(24),  KC_5, M(13),   M(14), M(15), M(16),   M(17),   M(18),   M(19),   M(20),    M(21),     M(22),  KC_GRV,   _______,  KC_BSPC,          KC_HOME, \
  KC_TAB,  KC_SCLN, KC_COMM,   KC_DOT,  KC_P,    KC_Y,      KC_F,     KC_G,      KC_C,      KC_R,       KC_L,        KC_SLSH,  KC_6,  KC_BSLS,                   KC_END, \
  KC_CAPS, KC_A,    KC_O,      KC_E,    KC_U,    KC_I,      KC_D,     KC_H,      KC_T,      KC_N,       KC_S,        KC_MINS,  KC_NUHS,  KC_ENT,                             \
  M(23), KC_NUBS, KC_QUOT,   KC_Q,    KC_J,    KC_K,      KC_X,     KC_B,      KC_M,      KC_W,       KC_V,        KC_Z,  KC_RO,    M(23),          KC_UP,            \
  KC_LCTL, KC_LGUI, KC_LALT, KC_MHEN,          KC_SPC,KC_SPC,                        KC_HENK,  KC_RALT,  KC_RCTL,  MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id)
    {
    case 0: // esc -> $
        if (record -> event.pressed)
        {
            //unregister_code(KC_LSFT);
            //return MACRO( I(_I), D(LSFT), T(4), U(LSFT), END );
			register_code(KC_LSFT);
			register_code(KC_4);
			unregister_code(KC_4);
			unregister_code(KC_LSFT);
        }
        break;
    case 1: // 1 -> &
        if (record -> event.pressed)
        {
			//unregister_code(KC_LSFT);
            //return MACRO( I(_I), D(LSFT), T(7), U(LSFT), END );
			register_code(KC_LSFT);
			register_code(KC_7);
			unregister_code(KC_7);
			unregister_code(KC_LSFT);
        }
        break;
    case 3: // 3 -> {
        if (record -> event.pressed)
        {
			//unregister_code(KC_LSFT);
            //return MACRO( I(_I), D(LSFT), T(LBRC), U(LSFT), END );
			register_code(KC_LSFT);
			register_code(KC_LBRC);
			unregister_code(KC_LBRC);
			unregister_code(KC_LSFT);
        }
        break;
    case 4: // 4 -> }
        if (record -> event.pressed)
        {
			register_code(KC_LSFT);
			register_code(KC_RBRC);
			unregister_code(KC_RBRC);
			unregister_code(KC_LSFT);
        }
        break;
    case 5: // 5 -> (
        if (record -> event.pressed)
        {
			register_code(KC_LSFT);
			register_code(KC_9);
			unregister_code(KC_9);
			unregister_code(KC_LSFT);
        }
        break;
    case 7: // 7 -> *
        if (record -> event.pressed)
        {
			register_code(KC_LSFT);
			register_code(KC_8);
			unregister_code(KC_8);
			unregister_code(KC_LSFT);
        }
        break;
    case 8: // 8 -> )
        if (record -> event.pressed)
        {
			register_code(KC_LSFT);
			register_code(KC_0);
			unregister_code(KC_0);
			unregister_code(KC_LSFT);
        }
        break;
    case 9: // 9 -> +
        if (record -> event.pressed)
        {
			register_code(KC_LSFT);
			register_code(KC_EQL);
			unregister_code(KC_EQL);
			unregister_code(KC_LSFT);
        }
        break;
    case 11: // [ -> !
        if (record -> event.pressed)
        {
			register_code(KC_LSFT);
			register_code(KC_1);
			unregister_code(KC_1);
			unregister_code(KC_LSFT);
        }
        break;
    case 12: // ] -> #
        if (record -> event.pressed)
        {
			register_code(KC_LSFT);
			register_code(KC_3);
			unregister_code(KC_3);
			unregister_code(KC_LSFT);
        }
        break;
    case 13: // unshifted 7 in _PDS
        if (record -> event.pressed)
        {
			unregister_code(KC_LSFT);
            register_code(KC_7);
			unregister_code(KC_7);
        }
        break;
    case 14: //unshifted 5 in _PDS
        if (record -> event.pressed)
        {
			unregister_code(KC_LSFT);
            register_code(KC_5);
			unregister_code(KC_5);
        }
        break;
    case 15: //unshifted 3 in _PDS
        if (record -> event.pressed)
        {
			unregister_code(KC_LSFT);
            register_code(KC_3);
			unregister_code(KC_3);
        }
        break;
    case 16: //unshifted 1 in _PDS
        if (record -> event.pressed)
        {
			unregister_code(KC_LSFT);
            register_code(KC_1);
			unregister_code(KC_1);
        }
        break;
    case 17: //unshifted 9 in _PDS
        if (record -> event.pressed)
        {
			unregister_code(KC_LSFT);
            register_code(KC_9);
			unregister_code(KC_9);
        }
        break;
    case 18: //unshifted 0 in _PDS
        if (record -> event.pressed)
        {
			unregister_code(KC_LSFT);
            register_code(KC_0);
			unregister_code(KC_0);
        }
        break;
    case 19: //unshifted 2 in _PDS
        if (record -> event.pressed)
        {
			unregister_code(KC_LSFT);
            register_code(KC_2);
			unregister_code(KC_2);
        }
        break;
    case 20: //unshifted 4 in _PDS
        if (record -> event.pressed)
        {
			unregister_code(KC_LSFT);
            register_code(KC_4);
			unregister_code(KC_4);
        }
        break;
    case 21: //unshifted 6 in _PDS
        if (record -> event.pressed)
        {
			unregister_code(KC_LSFT);
            register_code(KC_6);
			unregister_code(KC_6);
        }
        break;
    case 22: //unshifted 8 in _PDS
        if (record -> event.pressed)
        {
			unregister_code(KC_LSFT);
            register_code(KC_8);
			unregister_code(KC_8);
        }
        break;
	case 23:
		if (record -> event.pressed)
		{
			layer_on(_PDS);
			register_code(KC_LSFT);
		}
		else
		{
			layer_off(_PDS);
			unregister_code(KC_LSFT);
		}
		break;
	case 24: //unshifted grave in _PDS
		if (record -> event.pressed)
		{
			unregister_code(KC_LSFT);
			register_code(KC_GRV);
			unregister_code(KC_GRV);
		}
	case 25:
		if (record -> event.pressed)
		{
			register_code(KC_LSFT);
			register_code(KC_2);
			unregister_code(KC_2);
			unregister_code(KC_LSFT);
		}
    }
    return MACRO_NONE;
}

/* This is a list of user defined functions. F(N) corresponds to item N
   of this list.
 */
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(0),  // Calls action_function()
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t mods_pressed;
  static bool mod_flag;

  switch (id) {
    case 0:
      /* Handle the combined Grave/Esc key
       */
      mods_pressed = get_mods()&GRAVE_MODS; // Check to see what mods are pressed

      if (record->event.pressed) {
        /* The key is being pressed.
         */
        if (mods_pressed) {
          mod_flag = true;
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        /* The key is being released.
         */
        if (mod_flag) {
          mod_flag = false;
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
