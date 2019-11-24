#include "Graph.h"
#include "../LoadInfoAwal/loadinfoawal.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,NbB;
    TabBuildings BArr;
    MATRIKS Graff;
    GetInfoDariFile(&n,&m,&NbB,&BArr,&Graff);
        printf("here\n");
    Graph G;
    MakeEmptyGraf(&G);
    for(int i =1 ;i<=NbB;i++)
    {
        AddMotherLast(&G);
        for(int j =1;j<=NbB;j++)
        {
            if(Graff.Mem[i][j]==1)
            {
                AddNewChild(&G,i,j);
            }
        }
    }
    for(int i = 1;i<=NbB;i++)
    {
        printf("%d->",i);
        PrintInfo(MotherOfX(G,i));
        printf("\n");
    }
    return 0;
}