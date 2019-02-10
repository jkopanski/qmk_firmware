#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keycodes.h"
#include "tap_dance.h"

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
 *   |  L1  |   `  |  &/% | Left | Right|                                       |  Up  | Down |   #  |      |      |
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
    KC_TAB,        KC_QUOTE,            KC_COMMA,    KC_DOT,      KC_P,        KC_Y,     TD(HS_AP),
    _______,       KC_A,                KC_O,        KC_E,        KC_U,        KC_I,
    KC_LSPO,       RALT_T(KC_SCOLON),   KC_Q,        KC_J,        KC_K,        KC_X,     TD(HS_RBIND),
    OSL(1),        KC_GRV,              PD_DOL,      KC_LEFT,     KC_RIGHT,

                                                                       KC_INSERT,        KC_TRANSPARENT,
                                                                                         KC_HOME,
                                                     CTL_T(KC_BSPACE), ALT_T(KC_DELETE), KC_END,

    HS_LARR,         PD_STAR,  MAD_HAT,     PD_PLUS,     PD_RBRACKET,    PD_EXLM,      KC_BSLASH,
    _______,         KC_F,     KC_G,        KC_C,        KC_R,           KC_L,         KC_MINUS,
                     KC_D,     KC_H,        KC_T,        KC_N,           KC_S,         KC_SLASH,
    TD(HS_LBIND),    KC_B,     KC_M,        KC_W,        KC_V,           RALT_T(KC_Z), KC_RSPC,
                               KC_DOWN,     KC_UP,       MAD_HASH,       _______,      _______,

    KC_TRANSPARENT, KC_ESCAPE,
    KC_PGUP,
    KC_PGDOWN, ALT_T(KC_ENTER), CTL_T(KC_SPACE)
  ),

/* Keymap 1: Functions key and greek math symbols layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F7  |  F5  |  F3  |  F1  |  F9  |  F11 |           |  F12 |  F10 |  F2  |  F4  |  F6  |  F8  |   x    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   x  |   x  |   x  |   x  |   x  |      |           |      |   x  |   x  |   x  |   x  |   x  |   x    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   x  |   x  |   x  |   x  |   x  |------|           |------|   x  |   x  |   x  |   x  |   x  |   x    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   x  |   x  |   x  |   x  |   x  |      |           |      |   x  |   x  |   x  |   x  |   x  |   x    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L1  |   x  |   x  |   x  |   x  |                                       |   x  |   x  |   x  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ins  |      |       |      |  Esc |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | BkSp | Del  | Home |       | PgUp | Return |Space/|
 *                                 | Left | Left |------|       |------|  Left  |Left  |
 *                                 | Ctrl | Alt  | End  |       | PgDn |  Alt   |Ctrl  |
 *                                 `--------------------'       `----------------------'
 */
  [1] = LAYOUT_ergodox(
    _______,     KC_F7,       KC_F5,       KC_F3,       KC_F1,       KC_F9,       KC_F11,
    _______,     _______,     _______,     _______,     _______,     _______,     _______,
    _______,     _______,     _______,     _______,     _______,     _______,
    _______,     _______,     _______,     _______,     _______,     _______,     _______,
    _______,     _______,     _______,     _______,     _______,

                                                                     _______,     _______,
                                                                                  _______,
                                                        _______,     _______,     _______,

    KC_F12,      KC_F10,      KC_F2,       KC_F4,       KC_F6,       KC_F8,       _______,
    _______,     _______,     _______,     _______,     _______,     _______,     _______,
                 _______,     _______,     _______,     _______,     _______,     _______,
    _______,     _______,     _______,     _______,     _______,     _______,     _______,
                              _______,     _______,     _______,     _______,     _______,

    _______,     _______,
    _______,
    _______,     _______,     _______
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
