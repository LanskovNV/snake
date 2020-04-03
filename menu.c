/* leins, 20.05.2017 */
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <string.h>
#include "menu.h"
#include "game.h"

void PrintName(char* name, POSITION_t pos)
{
  int i, len;

  len = strlen(name);
  glColor3f(0, 0, 0);
  glRasterPos2f(pos.x, pos.y + 0.05);
  for (i = 0; i < len; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
} /* end of func */

void Draw(BUTTON_t button)
{
  float changeX, changeY;
  COLOR_t color;
  POSITION_t pos;

  /* color init */
  if (button.state == ACTIVE)
    color = button.hightColor;
  else
    color = button.color;

  /* button size */
  changeX = 0.4;
  changeY = 0.15;
  pos = button.pos;

  /* drawing */
  glBegin(GL_QUADS);
  glColor3f(color.R, color.G, color.B);
  glVertex2d(pos.x, pos.y);
  glVertex2d(pos.x, pos.y + changeY);
  glVertex2d(pos.x + changeX, pos.y + changeY);
  glVertex2d(pos.x + changeX, pos.y);
  glEnd();

  /* print button name */
  PrintName(button.name, button.pos);

} /* End of func */

void MenuInit(BUTTON_t *buttons)
{
  int j;
  COLOR_t color, hightColor;

  color.R = 1;
  color.G = 1;
  color.B = 0;
  hightColor.R = 0;
  hightColor.G = 0;
  hightColor.B = 1;

  /*
   * first is a start menu,
   * second is an end menu
  */
    for (j = 0; j < NUM_OF_BUTTONS; j++)
    {
      buttons[j].color = color;
      buttons[j].hightColor = hightColor;
      if (j == 0)
        {
          buttons[j].state = ACTIVE;
          buttons[j].pos.x = 0;
          buttons[j].pos.y = 0.6;
          strcpy(buttons[j].name, "start");
        }
      else if (j == 1)
        {
          buttons[j].state = PASSIVE;
          buttons[j].pos.x = 0;
          buttons[j].pos.y = 0.4;
          strcpy(buttons[j].name, "help");
        }
      else
        {
          buttons[j].state = PASSIVE;
          buttons[j].pos.x = 0;
          buttons[j].pos.y = 0.2;
          strcpy(buttons[j].name, "exit");
        }
    }

} /* end of func */


