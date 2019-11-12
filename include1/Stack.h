#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include "dinamicArr.h"
#include "List.h"

typedef struct{
    TabBuildings B;
    List P1,P2;
}State;

typedef struct StElmtList *stackAddress;
typedef struct StElmtList{
    State info;
    stackAddress next;
}StackElmt;

typedef struct{
    stackAddress top;
}Stack;

void SCreateEmpty(Stack *S);
/*
{I.S Anything}
{F.S Stack S defined}
*/

stackAddress Sallocate (State X);
/*
{I.S Anything}
{F.S X allocated as StackAddress}
*/ 

void Push (Stack *S,State X);
/*
{I.S Anything}
{F.S Stack Pushed with new Elmt X}
*/

void Pop (Stack *S,State *X);
/*
{I.S Anything}
{F.S Top Elmt of Stack Popped and Saved in X}
*/


#endif
