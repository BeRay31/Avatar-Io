#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Queue Q1,Q2;
    InitializeQueue(&Q1,&Q2);
    printf("Nbelmt Q1:%d Q2:%d\n",NBElmtQ(Q1),NBElmtQ(Q2));
    DelQ(&Q1,4);
    AddQ(&Q2,2);
    printf("Nbelmt Q1:%d Q2:%d\n",NBElmtQ(Q1),NBElmtQ(Q2));
    return 0;
}