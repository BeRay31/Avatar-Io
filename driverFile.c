#include <stdio.h>
#include "boolean.h"
//#include "infofileeksternal.h"
#include "save.h"


int main()
{
    int n,m,nbuildings;
    BuildingsArr arrBuildings;
    MATRIKS graf;
    GetInfoDariFile(&n,&m,&nbuildings,&arrBuildings,&graf);
    printf("%d %d\n",n,m );
    printf("%d\n",nbuildings);
    TulisIsiBangunan(arrBuildings);
    TulisMATRIKS(graf);
    Save(arrBuildings, graf, n, m, nbuildings);
    return 0;
}

// gcc driverFile.c mesinkar.c mesinkata.c loadinfoawal.c Buildings.c point.c matriks.c save.c load.c -o run