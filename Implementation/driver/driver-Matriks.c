#include "../../include1/matriks.h"
#include "../../include1/loadinfoawal.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,Nbuildings;
    TabBuildings Arrb;
    MATRIKS Mgraf;
    Buildings BTemp;
    GetInfoDariFile(&n,&m,&Nbuildings,&Arrb,&Mgraf);
    TulisMATRIKS(Mgraf);
    //Copy dan Make ada di dalam fungsi GetIndoDariFIle
    return 0;
}