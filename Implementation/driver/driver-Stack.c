#include "../../include1/Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Stack S;
    SCreateEmpty(&S);
    State St;
    TabBuildings BArr;
    MakeEmpty(&BArr,12);
    St.B = BArr;
    List P1,P2;
    CreateEmptyL(&P1);
    CreateEmptyL(&P2);
    St.P1 = P1;
    St.P2 = P2;
    stackAddress P = Sallocate(St);
    Push(&S,St);
    State del;
    Pop(&S,&del);
    return 0;
}