#ifndef __GAMEMECH_H__
#define __GAMEMECH_H__

#include "boolean.h"
#include "Map.h"
#include "loadinfoawal.h"

boolean NotEnd (BuildingsArr B);
void ChangeTurn(int *Turn);
boolean NotEndTurn(int i);
void EksekusiCommand(int command, int player, BuildingsArr *B);
void PrintPBuildings(int player, BuildingsArr B);
#endif