#ifndef TAP_DANCE_H
#define TAP_DANCE_H

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
  TRIPLE_HOLD = 7
};

// Tap dances
// I have mostly haskell related operators here
enum {
  HS_AP = 0,
  HS_LBIND,
  HS_RBIND,
  HS_LARR,
  HS_RARR,
};

#endif // TAP_DANCE_H
