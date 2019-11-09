#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>

typedef struct{
    Buildings B;
    int Player;
}infotype;
typedef struct StElmtList *stackAddress;
typedef struct StElmtList{
    infotype info;
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

stackAddress Sallocate (infotype X);
/*
{I.S Anything}
{F.S X allocated as StackAddress}
*/ 

void Push (Stack *S,infotype X);
/*
{I.S Anything}
{F.S Stack Pushed with new Elmt X}
*/

void Pop (Stack *S,infotype *X);
/*
{I.S Anything}
{F.S Top Elmt of Stack Popped and Saved in X}
*/


#endif
