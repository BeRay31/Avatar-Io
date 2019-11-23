#ifndef __GAMEMECH_H__
#define __GAMEMECH_H__

#include "boolean.h"
#include "Map.h"
#include "loadinfoawal.h"
#include "Stack.h"
#include "Queue.h"
#include "matriks.h"


typedef struct{
    int Neff;
    int T[30];
}idxArr;

boolean NotEnd (TabBuildings B);
/*
{I.S Game Launched}
{F.S Check the game if end return false if !end return true}
*/

void ChangeTurn(int *Turn,boolean changeTurn);
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

void EksekusiCommand(int command,Graph G, int player,boolean *changeTurn,List *P1List,List *P2List, TabBuildings *B,Stack *S,Queue *Q1, Queue *Q2, int n, int m, int nb);
/*
{I.S Command Defined}
{F.S Execute Command}
*/

void PrintOwnedBuildings(TabBuildings PBuildings, List PBIndex,int *NbofBuilding);
/*
{I.S Building Defined}
{F.S Players Building Printed}
*/

void PrintLinkedBuildingsA (int turn,Graph G,TabBuildings Buildings,int index,idxArr *T);
/*
{I.S Graph Defined and Building Defined for attack mech}
{F.S Printed Linked Building}
*/
void UpdateListBuilding(int index , List *PlayerB);
/*
{I.S List Index of Building defined}
{F.S List Index of Building updated}
*/
void PrintLinkedBuildingsM (int turn,Graph G,TabBuildings Buildings,int index,idxArr *T);//for attack mech
/*
{I.S Graph Defined and Building Defined for move mech}
{F.S Printed Linked Building}
*/
void resetAttacknMove(TabBuildings *B);
/*
{I.S attck true or false}
{F.S attack false}
*/
void UpdateLoadBuilding(TabBuildings *Arrb);
/*
{I.S Building not updated lvl and armies}
{F.S Building Updated}
*/
void PrintSkill(Queue Q);
/*
{I.s Skill defined}
{F.S Skill printed}
*/
void CopyState (State Ssrc,State *Sdest);
/*
{I.S State defined}
{F.S Ssrc copied to Sdest}
*/
void IncBuildingTroop (TabBuildings *B, int owner);
/*
{I.S Building owner == owner defined}
{F.S All armies on building incremented depends on its type}
*/
int CountPrintLinkedBuildingsM (int turn,Graph G,TabBuildings Buildings,int index);
/*
{I.s Linked Graph defined}
{F.S return number of building that linked that possible to move armied on there}
*/
int CountPrintLinkedBuildingsA (int turn,Graph G,TabBuildings Buildings,int index);
/*
{I.S Linked Graph defined}
{F.S return number of building that linked and possible to attack by building that have index == index}
*/
#endif