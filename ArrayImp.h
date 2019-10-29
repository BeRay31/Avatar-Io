#ifndef __ARRIMPT_H__
#define __ARRIMP_H__
#define IdxMax 1000
#define IdxMin 1
#define IdxUndef -999 
#define ValUndef -999
#include "boolean.h"
typedef int IdxType;
typedef int ElType;   
 
typedef struct { 
  Buildings TI[IdxMax+1];
} TabInt;
typedef struct{
    unsigned short int owner; //owner 1 or 2 or 0
    int armies; // total army in building
    unsigned short int level; //building's level 1 2 3 4
    int incArmy; //increment army depends on levels (A) / turn
    int maxArmyOnBuildings; //Max Army in Building (M)
    int X; // valUndef = -999
    int Y; // valUndef = -999
    boolean defenses; //defenses status yes = true , no = false
    int minArmiesToOccupy; //precondition to occupy an free building (total army) auto to level 1
    char buildingsType; //
} Buildings;
    

#define Elmt(T,i) (T).TI[(i)]

void MakeEmpty (TabInt * T);
int NbOfBuildings (TabInt T);
boolean IsPointBuilding (TabInt T, int x, int y);
void AddBuilding(TabInt *T, int owner, int armies, boolean defenses, char type, int x, int y);
#endif