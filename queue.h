#ifndef QUEUE_H
#define QUEUE_H
#include "types.h"
/*
 * ---==QUEUE==---
 * head->...->tail->
 */

/* types */
typedef struct tagLIST{
    COLOR_t color;
    POSITION_t pos;
    struct tagLIST *Next;
}LIST_t;

typedef struct{
    LIST_t *Head, *Tail;
}QUEUE_t;

/* functions */
int ListLen(LIST_t *L);
int Put(QUEUE_t *snake, COLOR_t newColor, POSITION_t newPos);
void Get(QUEUE_t *T);
#endif // QUEUE_H
