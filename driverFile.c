#include <stdio.h>
#include "infofileeksternal.h"

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
    return 0;
}