#include <stdio.h>
#include "../include1/boolean.h"
#include "../include1/loadinfoawal.h"
#include "../include1/save.h"
#include "../include1/Map.h"


int main()
{
    BuildMap Peta;
    int n,m,nbuildings;
    BuildingsArr arrBuildings;
    MATRIKS graf;
    GetInfoDariFile(&n,&m,&nbuildings,&arrBuildings,&graf);
    printf("%d %d\n",n,m );
    printf("%d\n",nbuildings);
    TulisIsiBangunan(arrBuildings);
    TulisMATRIKS(graf);
    printf("\n");
   /* Save(arrBuildings, graf, n, m, nbuildings);
    return 0;*/


    

}

// gcc driverFile.c mesinkar.c mesinkata.c loadinfoawal.c Buildings.c point.c matriks.c save.c load.c -o run