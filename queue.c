/* leins, 15.05.2017 */
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "queue.h"

int ListLen(LIST_t *L)
{
  int cnt = 0;

  while (L != NULL)
  {
    cnt++;
    L = L->Next;
  }
  return cnt;
}
int Put(QUEUE_t *T, COLOR_t newColor, POSITION_t newPos)
{
  LIST_t *tmp = malloc(sizeof(LIST_t));

  if (tmp == NULL)
    return 0;

  tmp->color = newColor;
  tmp->pos = newPos;
  tmp->Next = NULL;
  if (T->Head == NULL)
  {
    T->Head = tmp;
    T->Tail = T->Head;
  }
  else if (T->Head == T->Tail)
  {
    T->Head->Next = tmp;
    T->Tail = tmp;
  }
  else
  {
    T->Tail->Next = tmp;
    T->Tail = T->Tail->Next;
  }

  return 1;
}/* End of put func */

void Get(QUEUE_t *T)
{
  LIST_t *tmp;

  if (T->Head == NULL)
    return;
  else if (T->Head == T->Tail)
  {
    T->Head = NULL;
    free(T->Head);
  }
  else
  {
    tmp = T->Head;
    T->Head = T->Head->Next;
    tmp = NULL;
    free(tmp);
  }
}/* End of get func */
