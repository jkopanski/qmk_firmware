#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  [/7 |  {/5 |  }/3 |  @/1 |  =/9 |  ->  |           |  <-  | * /0 |  ^/2 |  +/4 |  ]/6 |  !/8 |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  |  Ap  |           |      |   F  |   G  |   C  |   R  |   L  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   /    |
 * |--------+------+------+------+------+------| Bind |           | Bind |------+------+------+------+------+--------|
 * | LSft/( |;/RAlt|   Q  |   J  |   K  |   X  | LGui |           | lGui |   B  |   M  |   W  |   V  |Z/RAlt| )/RSft |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|   `  |  &/% | Left | Right|                                       |  Up  | Down |   #  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ins  |      |       |      |  Esc |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | BkSp | Del  | Home |       | PgUp | Return |Space/|
 *                                 | Left | Left |------|       |------|  Left  |Left  |
 *                                 | Ctrl | Alt  | End  |       | PgDn |  Alt   |Ctrl  |
 *                                 `--------------------'       `----------------------'
 */
  [0] = LAYOUT_ergodox(
    _______,       PD_LBRACKET,         PD_LBRC,     PD_RBRC,     MAD_AT,      PD_EQ,    HS_RARR,
    KC_TAB,        KC_QUOTE,            KC_COMMA,    KC_DOT,      KC_P,        KC_Y,     GUI_T(KC_LBRACKET),
    _______,       KC_A,                KC_O,        KC_E,        KC_U,        KC_I,
    KC_LSPO,       RALT_T(KC_SCOLON),   KC_Q,        KC_J,        KC_K,        KC_X,     KC_EQUAL,
    _______,       KC_GRV,              PD_DOL,      KC_LEFT,     KC_RIGHT,

                                                                                KC_INSERT,        KC_TRANSPARENT,
                                                                                                  KC_HOME,
                                                              CTL_T(KC_BSPACE), ALT_T(KC_DELETE), KC_END,

    HS_LARR,             PD_STAR,  MAD_HAT,     PD_PLUS,     PD_RBRACKET,    PD_EXLM,      KC_BSLASH,
    RGUI_T(KC_RBRACKET), KC_F,     KC_G,        KC_C,        KC_R,           KC_L,         KC_MINUS,
                         KC_D,     KC_H,        KC_T,        KC_N,           KC_S,         KC_SLASH,
    KC_ASTR,             KC_B,     KC_M,        KC_W,        KC_V,           RALT_T(KC_Z), KC_RSPC,
                                   KC_UP,       KC_DOWN,     MAD_HASH,       _______,      _______,

    KC_TRANSPARENT, KC_ESCAPE,
    KC_PGUP,
    KC_PGDOWN, ALT_T(KC_SPACE), CTL_T(KC_ENTER)
  ),
};

bool suspended = false;
/* const uint16_t PROGMEM fn_actions[] = { */
/*   [1] = ACTION_LAYER_TAP_TOGGLE(1) */
/* }; */

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
/* const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) */
/* { */
/*       switch(id) { */
/*         case 0: */
/*         if (record->event.pressed) { */
/*           SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION); */
/*         } */
/*         break; */
/*       } */
/*     return MACRO_NONE; */
/* }; */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     // dynamically generate these. */
/*     case EPRM: */
/*       if (record->event.pressed) { */
/*         eeconfig_init(); */
/*       } */
/*       return false; */
/*       break; */
/*   } */
/*   return true; */
/* } */

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
