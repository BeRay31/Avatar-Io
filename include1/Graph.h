#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "List.h"

typedef struct ArrGraph{
    int NbElmt;
    List *Arr;
}GraphArr;

void CreateEmptyGraph(GraphArr *G,int NbElmt);
/*
{I.S Anything}
{F.S graph defined}
*/

void addGraph (GraphArr *Ga,int src,int NewElm);
/*
{I.S Graph defined}
{F.S add NewElmt as new edge of the srcth graph}
*/

void printGraph (GraphArr Ga);
/*
{I.S Graph Defined}
{F.S Graph Printed}
*/
#endif