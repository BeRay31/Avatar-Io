#ifndef __MAP_H__
#define __MAP_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Matriks/matriks.h"
#include "../Buildings/Buildings.h"
#include "../LoadInfoAwal/loadinfoawal.h"
#include "../Graph/Graph.h"
#include "../pColor/pcolor.h"

typedef int indeks; /* indeks baris, kolom */
typedef Buildings ElmtType;
typedef struct {
    ElmtType M[BrsMax+1][KolMax+1];
    Graph G;
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
    int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} BuildMap;

void MakeBMap(BuildMap *Map);
/*
{I.S Anything}
{F.S Matrix of Building Initiated}
*/

void UpdateMap (BuildMap *Map,TabBuildings b);
/*
{I.S Defined}
{F.S Update Map with new Building Information}
*/

void PrintMap(BuildMap Map);
/*
{I.S Map defined}
{F.S Map Printed}
*/



#endif
