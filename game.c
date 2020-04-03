/* leins, 15.05.2017 */
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "game.h"
#include "queue.h"
#include "graphics.h"

#define MAGIC 6
#define START_LENGTH 3

void SnakeInit(SNAKE_t *snake, int *speed)
{
  int i;
  COLOR_t color;
  POSITION_t pos;
  float delta = 2. / NUM_OF_CELLS;

  /* maybe some check should be here... */

  *speed = 0;

  snake->state = UP;
  pos.x = 0;
  pos.y = 0;
  for (i = 0; i < START_LENGTH; i++)
  {
    if (snake->python.Head == NULL)
    {
      color.R = 1;
      color.G = 1;
      color.B = 0;
    }
    else
    {
      color.R = 0;
      color.G = 0;
      color.B = 1;
    }
    pos.y -= delta;
    Put(&snake->python, color, pos);
  }
} /* end of func */

static void s_GoNext(LIST_t **L, POSITION_t lastPos)
{
  POSITION_t tmp;

  while ((*L)->Next != NULL)
  {
    L = &(*L)->Next;
    tmp = lastPos;
    lastPos = (*L)->pos;
    (*L)->pos = tmp;
  }
} /* end of func */

static int s_Eating(APPLE_t apples[], QUEUE_t *snake)
{
  int i;

  for (i = 0; i < NUM_OF_APPLES; i++)
  {
    if (apples[i].pos.x == snake->Head->pos.x &&
        apples[i].pos.y == snake->Head->pos.y)
    {
      apples[i].isEaten = TRUE;
      return 1;
    }
  }

  return 0;
}/* end of func */

int IsBadPos(LIST_t *snake)
{
  LIST_t *head = snake;
  float delta = 2. / NUM_OF_CELLS;

  snake = snake->Next;
  while (snake != NULL)
  {
    if (snake->pos.x == head->pos.x &&
        snake->pos.y == head->pos.y)
      return 1;
    if (snake->pos.x < -1 ||
        snake->pos.x > 1 - delta ||
        snake->pos.y > 1 ||
        snake->pos.y < -1 + delta)
      return 1;
    snake = snake->Next;
  }

  return 0;
} /* end of func */

int SnakeUpdate(SNAKE_t *snake, ORIENT_t newState, APPLE_t apples[], int *speed)
{
  LIST_t *tmp = malloc(sizeof(LIST_t));
  float delta = 2. / NUM_OF_CELLS;
  static int denum = 5;

  if (tmp == NULL)
    return 0;

  if (IsBadPos(snake->python.Head))
  {
    return 0;
  }
  else
  {
    POSITION_t lastPos = snake->python.Head->pos;
    POSITION_t oldTail = snake->python.Tail->pos;

    snake->state = newState;

    /* move head */
    switch (snake->state)
    {
    case UP:
      snake->python.Head->pos.y += delta;
      break;
    case DOWN:
      snake->python.Head->pos.y -= delta;
      break;
    case LEFT:
      snake->python.Head->pos.x -= delta;
      break;
    case RIGHT:
      snake->python.Head->pos.x += delta;
      break;
    }

    /* move snake */
    s_GoNext(&snake->python.Head, lastPos);

    if (s_Eating(apples, &snake->python))
      Put(&snake->python, snake->python.Tail->color, oldTail);
    if (ListLen(snake->python.Head) % denum == 0)
    {
      *speed += 15;
      denum += 5;
    }
    return 1;
  }
}/* end of func */

static void s_PutApple(APPLE_t *app)
{
  float change = 2. / NUM_OF_CELLS;

  srand(time(0));
  app->pos.x= pow(-1, rand() % MAGIC) * change * ((rand() % (NUM_OF_CELLS / 2)));
  app->pos.y = pow(-1, rand() % MAGIC) * change * ((rand() % (NUM_OF_CELLS / 2)));
  app->isEaten = FALSE;
} /* end of func */

void AppleUpdate(APPLE_t apples[])
{
  int i;
  //float change = 2. / NUM_OF_CELLS;

  for (i = 0; i < NUM_OF_APPLES; i++)
    s_PutApple(&apples[i]);
}/* end of func */


