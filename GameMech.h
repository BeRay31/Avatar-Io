#ifndef __GAMEMECH_H__
#define __GAMEMECH_H__

#include "boolean.h"
#include "Map.h"
#include "infofileeksternal.h"

boolean NotEnd (BuildingsArr B);
/*
{I.S Game Launched}
{F.S Check the game if end return false if !end return true}
*/

void ChangeTurn(int *Turn);
/*
{I.S Game Launched}
{F.S Turn Changed}
*/
int OlahString(Kata Kata);
/*
{I.S Kata Defined}
{F.S Return Int representation of Kata based on command list}
*/
boolean NotEndTurn(int i);
/*
{I.S Game Launched}
{F.S Check the Turn if End return False, if !end return true}
*/

void EksekusiCommand(int command, int player, BuildingsArr *B);
/*
{I.S Command Defined}
{F.S Execute Command}
*/

void PrintPBuildings(int player, BuildingsArr B);
/*
{I.S Building Defined}
{F.S Players Building Printed}
*/

void PrintLinkedBuildings (Buildings B,GraphArr G,int Owner);//not implemented yet
/*
{I.S Graph Defined and Building Defined}
{F.S Printed Linked Building}
*/
#endif