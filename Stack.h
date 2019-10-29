#ifndef __STACK_H__
#define __STACK_H__

#include "Stack.h"

typedef int infotype;
typedef struct StElmtList *stackAddress;
typedef struct StElmtList{
    infotype info;
    stackAddress next;
}StackElmt;


#endif