#include "../include1/Graph.h"

void CreateEmptyGraph(GraphArr *G,int NElmt)
{
    G = (GraphArr*)malloc(NElmt*(sizeof(GraphArr)));
    if ((*G).Arr != NULL)
    {
        (*G).NbElmt = NElmt;
    }
    else
    {
        (*G).NbElmt = 0;
    }
}
/*
{I.S Anything}
{F.S graph defined}
*/

void addGraph (GraphArr *Ga,int src,int NewElm)
{
    address NewElmt;
    NewElmt = AllocateL(NewElm);
    if (NewElmt != NULL)
    {
        InsertLast(&(*Ga).Arr[src],NewElmt);
    }
}
/*
{I.S Graph defined}
{F.S add NewElmt as new edge of the srcth graph}
*/
