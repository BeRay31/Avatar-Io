#include <stdio.h>
#include "../include1/boolean.h"
#include "../include1/loadinfoawal.h"
#include "../include1/save.h"
#include "../include1/Map.h"
#include "../include1/GameMech.h"

int main()
{
    List P1Buildings,P2Buildings;
    BuildMap Peta;
    int n,m,nbuildings;
    TabBuildings arrBuildings;
    MATRIKS graf;
    Stack S;
    SCreateEmpty(&S);
    InsertLast(&P1Buildings,AllocateL(1));//Initiate and allocate Building index 1 == owner P1
    InsertLast(&P2Buildings,AllocateL(2));//Initiate and allocate Building index 2 == owner P2
    InsertLast(&P1Buildings,AllocateL(13));
    InsertLast(&P2Buildings,AllocateL(17));
    GetInfoDariFile(&n,&m,&nbuildings,&arrBuildings,&graf);
    printf("%d %d\n",n,m );
    printf("%d\n",nbuildings);
    TulisTabBuilding(arrBuildings);
    TulisMATRIKS(graf);
    printf("\n");
   /* Save(arrBuildings, graf, n, m, nbuildings);
    return 0;*/
    /*
    UpdateLoadBuilding(&arrBuildings);
    arrBuildings.TI[1].armies = 80;
    arrBuildings.TI[13].armies = 40;
    arrBuildings.TI[13].owner = 1;
    arrBuildings.TI[17].armies =40;
    arrBuildings.TI[17].owner=2;
    MakeBMap(&Peta);
    UpdateMap(&Peta,arrBuildings);
    PrintMap(Peta);
    EksekusiCommand(1,Peta.G,1,&P1Buildings,&P2Buildings,&arrBuildings,&S);
    UpdateMap(&Peta,arrBuildings);
    PrintMap(Peta);
    EksekusiCommand(1,Peta.G,1,&P1Buildings,&P2Buildings,&arrBuildings,&S);
    UpdateMap(&Peta,arrBuildings);
    PrintMap(Peta);
    EksekusiCommand(1,Peta.G,2,&P1Buildings,&P2Buildings,&arrBuildings,&S);
    */
    return 0;
}

// gcc driverFile.c mesinkar.c mesinkata.c loadinfoawal.c Buildings.c point.c matriks.c save.c load.c -o run