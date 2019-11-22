#include "../include1/Graph.h"


GraphAddress AllocateEmptyG (int x)
{
    GraphAddress G = (GraphAddress)malloc(sizeof(GraphElmt));
    if (G != NULL)
    {
        G->Child.First= NULL;
        G->Mother = NULL;
        G->index = x;
        return G;
    }
    else
    {
        return NULL;    
    }
}


void MakeEmptyGraf(Graph *G)
{
    (*G).FirstG = NULL;
}
/*
{I.S Anything}
{F.S EmptyGraff defined as First = NULL}
*/

void AddMotherLast(Graph *G)
{
    if((*G).FirstG == NULL)
    {
        (*G).FirstG = AllocateEmptyG(1);
    }
    else
    {
        int x = 2;
        GraphAddress NewElmt = (*G).FirstG;
        while (NewElmt->Mother != NULL)
        {
            NewElmt = NewElmt->Mother;
            x++;
        }
        NewElmt->Mother = AllocateEmptyG(x);
    }
}
/*
{I.S Graph Defined Can be Empty}
{F.S Add New Mother}
*/

void AddNewChild(Graph *G,int index,int x)
{
    GraphAddress MotherX = (*G).FirstG;
    while(MotherX->index != index)
    {
        MotherX = MotherX->Mother;
    }
    if(MotherX->Child.First == NULL)
    {
        MotherX->Child.First = AllocateL(x);
    }
    else
    {
        address y = MotherX->Child.First;
        while(y->next != NULL)
        {
            y = y->next;
        }
        y->next = AllocateL(x);
    }
}
/*
{I.S GrafDefined}
{F.S NewLast Child added}
*/
List MotherOfX(Graph G, int X)
{
    GraphAddress CurrentElmt = G.FirstG;
    while(CurrentElmt->index != X)
    {
        CurrentElmt = CurrentElmt->Mother;
    }
    List Child = CurrentElmt->Child;
    return Child;
}
/*
{I.S Graph Defined}
{F.S Return List from Graph index of X}
*/