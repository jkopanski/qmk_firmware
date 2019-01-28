#ifndef TAP_DANCE_H
#define TAP_DANCE_H

#include "process_keycode/process_tap_dance.h"

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7,
  NO_MORE = 8
};

// Tap dances
// I have mostly haskell related operators here
enum {
  HS_AP = 0,
  HS_LBIND,
  HS_RBIND,
  /* HS_LARR, */
  /* HS_RARR, */
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)
      return SINGLE_TAP;
    else
      return SINGLE_HOLD;
  }

  else if (state->count == 2) {
    if (state->interrupted)
      return DOUBLE_SINGLE_TAP;
    else if (state->pressed)
      return DOUBLE_HOLD;
    else
      return DOUBLE_TAP;
  }

  else if (state->count == 3) {
    if (state->interrupted || !state->pressed)
      return TRIPLE_TAP;
    else
      return TRIPLE_HOLD;
  }

  else return NO_MORE;
};

static tap ap_tap_state = {
  .is_press_action = true,
  .state = 0,
};

static tap rbind_tap_state = {
  .is_press_action = true,
  .state = 0,
};

static tap lbind_tap_state = {
  .is_press_action = true,
  .state = 0,
};

/* use static keys for now */
/* static tap rarr_tap_state = { */
/*   .is_press_action = true, */
/*   .state = 0, */
/* }; */

/* static tap larr_tap_state = { */
/*   .is_press_action = true, */
/*   .state = 0, */
/* }; */


void ap_finished (qk_tap_dance_state_t* state, void* user_data) {
  ap_tap_state.state = cur_dance(state);
  switch (ap_tap_state.state) {
    case SINGLE_TAP: SEND_STRING("$"); break;
    case DOUBLE_TAP: SEND_STRING("<$>"); break;
    case TRIPLE_TAP: SEND_STRING("<*>"); break;
  }
};

void ap_reset (qk_tap_dance_state_t* state, void* user_data) {
  switch (ap_tap_state.state) {
    case SINGLE_HOLD: unregister_code(KC_LGUI); break;
  }
  ap_tap_state.state = 0;
};

void rbind_finished (qk_tap_dance_state_t* state, void* user_data) {
  rbind_tap_state.state = cur_dance(state);
  switch (rbind_tap_state.state) {
    case SINGLE_TAP: SEND_STRING(">>="); break;
    case SINGLE_HOLD: register_code(KC_LGUI); break;
    case DOUBLE_TAP: SEND_STRING(">>"); break;
    case TRIPLE_TAP: SEND_STRING(">=>"); break;
  }
};

void rbind_reset (qk_tap_dance_state_t* state, void* user_data) {
  switch (rbind_tap_state.state) {
    case SINGLE_HOLD: unregister_code(KC_LGUI); break;
  }
  rbind_tap_state.state = 0;
};

void lbind_finished (qk_tap_dance_state_t* state, void* user_data) {
  lbind_tap_state.state = cur_dance(state);
  switch (lbind_tap_state.state) {
    case SINGLE_TAP: SEND_STRING("=<<"); break;
    case SINGLE_HOLD: register_code(KC_RGUI); break;
    case DOUBLE_TAP: SEND_STRING("<<"); break;
    case TRIPLE_TAP: SEND_STRING("<=<"); break;
  }
};

void lbind_reset (qk_tap_dance_state_t* state, void* user_data) {
  switch (lbind_tap_state.state) {
    case SINGLE_HOLD: unregister_code(KC_RGUI); break;
  }
  lbind_tap_state.state = 0;
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [HS_AP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ap_finished, ap_reset),
  [HS_RBIND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rbind_finished, rbind_reset),
  [HS_LBIND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lbind_finished, lbind_reset),
};

#endif // TAP_DANCE_H
