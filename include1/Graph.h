#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "List.h"
#include <stdlib.h>

typedef struct ElmtGraph *GraphAddress;
typedef struct ElmtGraph{
    GraphAddress Mother;
    List Child;
    int index;
}GraphElmt;

typedef struct graph{
    GraphAddress FirstG;
}Graph;

GraphAddress AllocateEmptyG (int x);
/*
{I.S Undefined}
{F.S Allocate neew GrphAddress}
*/

void MakeEmptyGraf(Graph *G);
/*
{I.S Anything}
{F.S EmptyGraff defined as First = NULL}
*/

void AddMotherLast(Graph *G);
/*
{I.S Graph Defined Can be Empty}
{F.S Add New Mother}
*/

void AddNewChild(Graph *G,int index,int x);
/*
{I.S GrafDefined}
{F.S NewLast Child added}
*/
List MotherOfX(Graph G, int X);
/*
{I.S Graph Defined}
{F.S Return List from Graph index of X}
*/

#endif