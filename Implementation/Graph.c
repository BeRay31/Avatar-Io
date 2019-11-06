#include "../include1/Graph.h"

void CreateEmptyGraph(GraphArr *G)
{  
    (*G).Arr.First = NULL;
}
/*
{I.S Anything}
{F.S graph defined}
*/

void addGraph (GraphArr *Ga,int src,int NewElm)
{
    addressG currentNode = (*Ga).Arr.First;
    addressG NewElmt = (addressG)malloc(sizeof(GElmtList));
    if (NewElmt!=NULL)
    {
        NewElmt->info = NewElm;
        NewElmt->nextNode = currentNode->nextNode;
        NewElmt->next = NULL;
    }
    while(currentNode->info != src)
    {
        currentNode = currentNode->nextNode;
    }
    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = NewElmt;

}
/*
{I.S Graph defined}
{F.S add NewElmt as new edge of the srcth graph}
*/

void printGraph (GraphArr Ga)
{
    address currentPrint = Ga.Arr->First;
    for (int i = 1; i<=Ga.NbElmt ;i++ )
    {
        while(currentPrint != NULL)
        {
            printf("%d",currentPrint->info);
            if(currentPrint->next != NULL)
            {
                printf("->");
            }
            currentPrint = currentPrint->next;
        }
        printf("\n");
    }
}
/*
{I.S Graph Defined}
{F.S Graph Printed}
*/