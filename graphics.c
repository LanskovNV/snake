/* leins, 15.05.2017 */
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "graphics.h"
#include "queue.h"

void PutField(void)
{
  float delta = 2. / NUM_OF_CELLS; // two is a field size
  float i;

  for (i = -1; i < NUM_OF_CELLS; i += delta)
  {
    /* draw vertical lines */
    glBegin(GL_LINES);
    glColor3f(FIELD_COLOR_R, FIELD_COLOR_G, FIELD_COLOR_B);
    glVertex2d(i, -1);
    glVertex2d(i, 1);
    glEnd();

    /* draw horisontal lines */
    glBegin(GL_LINES);
    glColor3f(FIELD_COLOR_R, FIELD_COLOR_G, FIELD_COLOR_B);
    glVertex2d(-1, i);
    glVertex2d(1, i);
    glEnd();
  }
}/* end of func */
void DrawSnake(LIST_t *python)
{
  float change = 2. / NUM_OF_CELLS;
  LIST_t **tmp = &python;

  while(*tmp != NULL)
  {
    glBegin(GL_QUADS);
    glColor3d((*tmp)->color.R, (*tmp)->color.G, (*tmp)->color.B);
    glVertex2d((*tmp)->pos.x, (*tmp)->pos.y);
    glVertex2d((*tmp)->pos.x + change, (*tmp)->pos.y);
    glVertex2d((*tmp)->pos.x + change, (*tmp)->pos.y - change);
    glVertex2d((*tmp)->pos.x, (*tmp)->pos.y - change);
    glEnd();

    tmp = &(*tmp)->Next;
  }
}/* end of func */

void DrawApples(APPLE_t apples[])
{
  float change = 2. / NUM_OF_CELLS;
  int i;

  for (i = 0; i < NUM_OF_APPLES; i++)
  {
    if (apples[i].isEaten == FALSE)
    {
      glBegin(GL_QUADS);
      glColor3d(0, 1, 0); // apples color
      glVertex2d(apples[i].pos.x, apples[i].pos.y);
      glVertex2d(apples[i].pos.x + change, apples[i].pos.y);
      glVertex2d(apples[i].pos.x + change, apples[i].pos.y - change);
      glVertex2d(apples[i].pos.x, apples[i].pos.y - change);
      glEnd();
    }
  }
}/* end of func */
