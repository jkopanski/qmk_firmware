#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(KC_DLR,KC_AMPR,KC_LBRACKET,KC_LCBR,KC_RCBR,KC_LPRN,KC_TRANSPARENT,KC_TILD,KC_QUOTE,KC_COMMA,KC_DOT,KC_P,KC_Y,GUI_T(KC_LBRACKET),KC_TAB,KC_A,KC_O,KC_E,KC_U,KC_I,KC_LSPO,RALT_T(KC_SCOLON),KC_Q,KC_J,KC_K,KC_X,KC_EQUAL,TG(1),KC_PIPE,KC_QUES,KC_LEFT,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,CTL_T(KC_BSPACE),ALT_T(KC_DELETE),KC_END,KC_TRANSPARENT,KC_RPRN,KC_PLUS,KC_RBRACKET,KC_EXLM,KC_HASH,KC_AT,RGUI_T(KC_RBRACKET),KC_F,KC_G,KC_C,KC_R,KC_L,KC_SLASH,KC_D,KC_H,KC_T,KC_N,KC_S,KC_MINUS,KC_ASTR,KC_B,KC_M,KC_W,KC_V,RALT_T(KC_Z),KC_RSPC,KC_UP,KC_DOWN,KC_LABK,KC_RABK,KC_CIRC,KC_TRANSPARENT,KC_ESCAPE,KC_PGUP,KC_PGDOWN,ALT_T(KC_SPACE),CTL_T(KC_ENTER)),

  [1] = LAYOUT_ergodox(KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_AMPR,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,GUI_T(KC_NO),KC_RBRACKET,KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSPO,RALT_T(KC_Z),KC_X,KC_C,KC_V,KC_B,KC_PERC,KC_TRANSPARENT,KC_QUOTE,KC_LALT,KC_LEFT,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,CTL_T(KC_BSPACE),ALT_T(KC_DELETE),KC_END,KC_PIPE,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,RGUI_T(KC_NO),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,KC_DLR,KC_N,KC_M,KC_COMMA,KC_DOT,RALT_T(KC_SLASH),KC_RSPC,KC_UP,KC_DOWN,KC_LBRACKET,KC_RBRACKET,KC_TRANSPARENT,KC_TRANSPARENT,KC_ESCAPE,KC_PGUP,KC_PGDOWN,ALT_T(KC_SPACE),CTL_T(KC_ENTER)),

};

bool suspended = false;
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
