#ifndef __ARRIMPT_H__
#define __ARRIMP_H__
#define IdxMax 1000
#define IdxMin 1
#define IdxUndef -999 
#define ValUndef -999
#include "boolean.h"
#include "Buildings.h"
typedef int IdxType;
typedef int ElType;   
 
typedef struct { 
  Buildings TI[IdxMax+1];//array of Building
} TabInt;


#define Elmt(T,i) (T).TI[(i)]

void MakeEmpty (TabInt * T);
/*
{I.S Anything}
{F.S Make Empty Array}
*/

int NbOfBuildings (TabInt T);
/*
{I.S T defined}
{F.S return NBElmt of T}
*/

boolean IsPointBuilding (TabInt T, int x, int y);
/*
{I.S T defined}
{F.S return true if x,y are position of Building}
*/

void AddBuilding(TabInt *T,Buildings B);
/*
{I.S T defined,B created}
{F.S Added new elmt on T}
*/
#endif