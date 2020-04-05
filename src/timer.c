/* leins, 26.05.2017 */
#include <GL/gl.h>
#include <GL/glut.h>
#include "timer.h"
#include "graphics.h"

extern APPLE_t apples[NUM_OF_APPLES];
extern int speed;

void AppleTimer(int value1)
{
  AppleUpdate(apples);
  glutTimerFunc(APPLE_TIME, AppleTimer, 0);
} /* end of timer func */

void Timer(int value)
{
  glutPostRedisplay();
  glutTimerFunc(DRAW_TIME - speed, Timer, 0);

} /* end of timer func */
