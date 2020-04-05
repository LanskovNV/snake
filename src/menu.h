#ifndef MENU_H
#define MENU_H
#include "types.h"

#define NUM_OF_BUTTONS 3

/* types */
typedef enum {
  GAME,
  MENU,
  HELP
}MODE_t;

typedef enum {
  ACTIVE,
  PASSIVE
}BUTTON_STATE_t;

typedef struct {
  POSITION_t pos;
  COLOR_t color, hightColor;
  BUTTON_STATE_t state;
  char name[10];
}BUTTON_t;

/* functions */
void Draw(BUTTON_t button);
void PrintName(char* name, POSITION_t pos);

#endif // MENU_H
