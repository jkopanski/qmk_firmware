#ifndef KEYCODES_H
#define KEYCODES_H

// #include "quantum/quantum_keycodes.h"
#include "ergodox_ez.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  // Typical programmer dvorak keycodes
  PD_DOL,      // $ and ~
  PD_AMP,      // & and %
  PD_LBRACKET, // [ and 7
  PD_LBRC,     // { and 5
  PD_RBRC,     // } and 3
  PD_LPAREN,   // ( and 1
  PD_EQ,       // = and 9
  PD_STAR,     // * and 0
  PD_RPAREN,   // ) and 2
  PD_PLUS,     // + and 4
  PD_RBRACKET, // ] and 6
  PD_EXLM,     // ! and 8
  PD_HASH,     // # and `
  // My own different keycodes
  // since I'll use space cadet for parens
  MAD_AT,      // @ and 1
  MAD_HAT,     // ^ and 2
  MAD_HASH,    // #
  // Haskell keycodes
  HS_RARR,     // ->
  HS_LARR,     // <-
};

// check for modifiers
#define SHIFT_MOD  (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))

__attribute__((always_inline))
inline void send_dvorak_key(uint8_t shift_pressed, char* k1, char* k2) {
  if (shift_pressed) {
    uint8_t mods = get_mods();
    unregister_mods(SHIFT_MOD);
    send_string(k2);
    register_mods(mods);
  } else {
    send_string(k1);
  }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint8_t shift_down;
  shift_down = get_mods() & SHIFT_MOD;

  switch (keycode) {
    case PD_DOL:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "$", "~");
      break;

    case PD_AMP:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "&", "%");
      break;

    case PD_LBRACKET:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "[", "7");
      break;

     case PD_LBRC:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "{", "5");
      break;

    case PD_RBRC:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "}", "3");
      break;

    case PD_LPAREN:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "(", "1");
      break;

    case PD_EQ:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "=", "9");
      break;

    case PD_STAR:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "*", "0");
      break;

    case PD_RPAREN:
      if (record->event.pressed)
        send_dvorak_key( shift_down, ")", "2");
      break;

    case PD_PLUS:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "+", "4");
     break;

    case PD_RBRACKET:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "]", "6");
      break;

    case PD_EXLM:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "!", "8");
      break;

    case PD_HASH:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "#", "`");
      break;

    // My own different keycodes
    // since I'll use space cadet for parens
    case MAD_AT:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "@", "1");
      break;

    case MAD_HAT:
      if (record->event.pressed)
        send_dvorak_key( shift_down, "^", "2");
      break;

    case MAD_HASH:
      if (record->event.pressed) {
        SEND_STRING("#");
      }
      break;

    // Haskell keycodes
    case HS_RARR:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      break;

    case HS_LARR:
      if (record->event.pressed) {
        SEND_STRING("<-");
      }
      break;
  }
  return true;
};

#endif // KEYCODES_H
