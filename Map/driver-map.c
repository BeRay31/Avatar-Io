#include "Map.h"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    BuildMap Map;
    MakeBMap(&Map);
    PrintMap(Map);
    Map.M[10][3].owner = 1;
    TabBuildings ArrB;
    MakeEmpty(&ArrB,1);
    CreateBuildings(&ArrB.TI[1],'C');
    ArrB.TI[1].owner = 1;
    ArrB.TI[1].position.X = 10;
    ArrB.TI[1].position.Y = 1;
    UpdateMap(&Map,ArrB);
    PrintMap(Map);
    return 0;
}