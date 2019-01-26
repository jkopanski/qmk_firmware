#ifndef KEYCODES_H
#define KEYCODES_H

#include "quantum/quantum_keycodes.h"

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
};

#endif // KEYCODES_H
