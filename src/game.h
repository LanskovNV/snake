#ifndef GAME_H
#define GAME_H
#include "queue.h"
#include "graphics.h"
/* types */
typedef enum {
  UP,
  DOWN,
  LEFT,
  RIGHT
}ORIENT_t;

typedef struct {
  QUEUE_t python;
  ORIENT_t state;
}SNAKE_t;

/* functions */
int IsBadPos(LIST_t *snake);
void SnakeInit(SNAKE_t *snake, int *speed);
int SnakeUpdate(SNAKE_t *snake, ORIENT_t newState, APPLE_t apples[], int *speed);
void AppleUpdate(APPLE_t apples[]);

#endif // GAME_H
