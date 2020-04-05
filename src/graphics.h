#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "queue.h"

#define NUM_OF_APPLES 1
#define NUM_OF_CELLS 32
#define FIELD_COLOR_R 0
#define FIELD_COLOR_G 0
#define FIELD_COLOR_B 0
/* types */

typedef enum {
  FALSE,
  TRUE
}BOOL;

typedef struct {
  POSITION_t pos;
  BOOL isEaten;
}APPLE_t;

/* functions */
void PutField(void);
void DrawSnake(LIST_t *python);
void DrawApples(APPLE_t apples[]);
#endif // GRAPHICS_H
