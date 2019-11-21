#include "../include1/Graph.h"

//Building Relation

GraphArr CreateBaseGraph(int NBuilding)
{  
    GraphArr G;
    (G).NbElmt = NBuilding;
    for (int i = 0; i<=NBuilding;i++)
    {
        (G).Arr[i].First = NULL;
    }
    return G;
}
/*
{I.S Anything}
{F.S graph defined}
*/

void addGraph (GraphArr *Ga,int src,int NewElm)
{
    address  NewElmt = AllocateL(NewElm);
    if (NewElmt != NULL)
    {
        InsertLast(&(*Ga).Arr[src],NewElmt);
    }
}
/*
{I.S Graph defined}
{F.S add NewElmt as new edge of the srcth graph}
*/

void printGraph (GraphArr Ga)
{
    address current;
    for (int i = 1;i<=Ga.NbElmt;i++)
    {
        printf("%d",i);
        current =Ga.Arr[i].First; 
        while(current != NULL)
        {
            printf("->%d",current->info);
            current = current->next;
        }
        printf("\n");
    }
}
/*
{I.S Graph Defined}
{F.S Graph Printed}
*/