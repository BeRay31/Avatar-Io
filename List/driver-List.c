#include "List.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    address P = AllocateL(12);
    List L;
    CreateEmptyL(&L);
    PrintInfo(L);
    printf("\n");
    if (IsEmpty(L))
    {
        InsertFirst(&L,P);
    }
    PrintInfo(L);
    printf("\n");
    InsertAfter(&L,AllocateL(10),P);
    PrintInfo(L);
    printf("\n");
    InsertLast(&L,AllocateL(21));
    PrintInfo(L);
    printf("\n");
    address del;
    DelP(&L,&del,P);
    PrintInfo(L);
    printf("\n");
    return 0;
}