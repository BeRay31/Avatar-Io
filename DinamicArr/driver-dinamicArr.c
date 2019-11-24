#include "dinamicArr.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    TabBuildings ArrB;
    MakeEmpty(&ArrB,3);
    printf("maxEl:%d,Neff:%d\n",ArrB.MaxEl,ArrB.Neff);
    //-----------------------------------------------
    Buildings Temp;
    CreateBuildings(&Temp,'C');
    Temp.armies = 50;
    ArrB.TI[1] = Temp;
    CreateBuildings(&Temp,'T');
    Temp.armies = 20;
    ArrB.TI[2] = Temp;
    CreateBuildings(&Temp,'V');
    Temp.armies = 20;
    ArrB.TI[3] = Temp;
    TulisTabBuilding(ArrB);
    TabBuildings TempBArr;
    CopyTab(ArrB,&TempBArr);
    TulisTabBuilding(TempBArr);
    printf("%d\n",NbOfBuildings(TempBArr,1));
    return 0 ;
}