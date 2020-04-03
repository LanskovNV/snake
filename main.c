/* leins, 15.05.2017 */
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "graphics.h"
#include "queue.h"
#include "game.h"
#include "menu.h"
#include "timer.h"

#define MAPP 600
#define HELP_STR_1 "snake is a very simple game, use 'w' 'a' 's' 'd' to move"
#define HELP_STR_2 "when eat apple, snake length increases"
#define HELP_STR_3 "when you touch a walls or eat yourself - gameover"
#define HELP_STR_4 "(press 'q' to return to the menu)"

/* snake defenition */
SNAKE_t g_snake;
ORIENT_t newState = UP;
int speed = 0;

/* apples definition */
APPLE_t apples[NUM_OF_APPLES];

/* menu init */
MODE_t mode = MENU;
BUTTON_t buttons[NUM_OF_BUTTONS];

void Keyboard(unsigned char Key, int MouseX, int MouseY)
{
  if (Key == 27) // escape
    exit(0);

  switch (mode)
  {
    case GAME:
    if (Key == 'w')
      if (g_snake.state != DOWN)
        newState = UP;
    if (Key == 's')
      if (g_snake.state != UP)
        newState = DOWN;
    if (Key == 'a')
      if (g_snake.state != RIGHT)
        newState = LEFT;
    if (Key == 'd')
      if (g_snake.state != LEFT)
        newState = RIGHT;
    break;
  case MENU:
    if (Key == 13) // enter
    {
      int i;

      for (i = 0; i < NUM_OF_BUTTONS; i++)
      {
        if (buttons[i].state == ACTIVE)
        {
          if (i == 0)
          {
            while (g_snake.python.Head != NULL)
              Get(&g_snake.python);
            SnakeInit(&g_snake, &speed);
            mode = GAME;
          }
          if (i == 1)
            mode = HELP;
          if (i == 2)
            exit(0);
        }
      }
    }
    if (Key == 'w')
    {
      int i;

      for (i = 0; i < NUM_OF_BUTTONS; i++)
      {
        if (buttons[i].state == ACTIVE)
        {
          buttons[i].state = PASSIVE;
          --i;
          if (i < 0)
            i += NUM_OF_BUTTONS;
          buttons[i].state = ACTIVE;
        }
      }
    }
    if (Key == 's')
    {
      int i;

      for (i = 0; i < NUM_OF_BUTTONS; i++)
      {

        if (buttons[i].state == ACTIVE)
        {
          buttons[i].state = PASSIVE;
          i++;
          if (i >= NUM_OF_BUTTONS)
            i -= NUM_OF_BUTTONS;
          buttons[i].state = ACTIVE;
        }
      }
    }
    break;
  case HELP:
    if (Key == 'q')
      mode = MENU;
    break;
  }
}/* End of Keyboard function */

void Display(void)
{
  int but;
  POSITION_t helpPos1, helpPos2, helpPos3, helpPos4;

  /* help position init */
  helpPos1.x = -1;
  helpPos1.y = 0.5;
  helpPos2.x = -1;
  helpPos2.y = 0.3;
  helpPos3.x = -1;
  helpPos3.y = 0.1;
  helpPos4.x = -1;
  helpPos4.y = -0.1;

  /* clear screen */
  glClearColor(0.3, 0.4, 0.2, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  switch (mode)
  {
  case GAME:
    SnakeUpdate(&g_snake, newState, apples, &speed);
    DrawApples(apples);
    DrawSnake(g_snake.python.Head);
    PutField();
    if (IsBadPos(g_snake.python.Head))
      mode = MENU;
    break;
  case MENU:
    for (but = 0; but < NUM_OF_BUTTONS; but++)
      Draw(buttons[but]);
    break;
  case HELP:
    PrintName(HELP_STR_1, helpPos1);
    PrintName(HELP_STR_2, helpPos2);
    PrintName(HELP_STR_3, helpPos3);
    PrintName(HELP_STR_4, helpPos4);
    break;
  }

  /* buffers */
  glFlush();
  glutSwapBuffers();
}/* End of Display func */

int main(int argc, char *argv[])
{
  /* Initialization */
  SnakeInit(&g_snake, &speed);
  MenuInit(buttons);

  /* glut init */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

  /* creating window */
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(MAPP, MAPP);
  glutCreateWindow("snake");
  /* -==- */

  AppleUpdate(apples);

  glutTimerFunc(APPLE_TIME, AppleTimer, 1);
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  glutTimerFunc(DRAW_TIME - speed, Timer, 0);

  glutMainLoop();
  return 0;
}/* End of main */
