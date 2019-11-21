#include "graph_new.h"
#include "include1/loadinfoawal.h"


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