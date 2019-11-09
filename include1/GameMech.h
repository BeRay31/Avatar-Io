#ifndef __GAMEMECH_H__
#define __GAMEMECH_H__

#include "boolean.h"
#include "Map.h"
#include "loadinfoawal.h"
#include "Queue.h"
#include "Stack.h"

boolean NotEnd (TabBuildings B);
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

void EksekusiCommand(int command,GraphArr G, int player,List *PList, TabBuildings *B, Queue *QP,StackElmt *S);
/*
{I.S Command Defined}
{F.S Execute Command}
*/

void PrintOwnedBuildings(TabBuildings PBuildings, List PBIndex,int *NbofBuilding);
/*
{I.S Building Defined}
{F.S Players Building Printed}
*/

void PrintLinkedBuildingsA (int turn,GraphArr G,TabBuildings Buildings,int index,int *NbofBuilding);//for attack mech
/*
{I.S Graph Defined and Building Defined for attack mech}
{F.S Printed Linked Building}
*/
void UpdateListBuilding(int index , List *PlayerB);
/*
{I.S List Index of Building defined}
{F.S List Index of Building updated}
*/
void PrintLinkedBuildingsM (int turn,GraphArr G,TabBuildings Buildings,int index,int *NbofBuilding);//for attack mech
/*
{I.S Graph Defined and Building Defined for move mech}
{F.S Printed Linked Building}
*/
#endif