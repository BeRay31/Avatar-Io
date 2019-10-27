#include "Buildings.h"
//IMPLEMENTATION

void CreateBuildings (Buildings *B,char type);
/*
{I.S anything}
{F.S Building Created Based on Type}
*/
void ChangeOwner(Buildings *B);
/*
{I.S Owner 1 = P1 2 = P2}
{F.S switch to 1 or 2}
*/
void LevelUp (Buildings *B);
/*
{I.S level 1 2 3}
{F.S level++ and <=4}
*/
void IncTroops (Buildings *B);
/*
{I.S Anything}
{F.S Total Army incremented by (A)}
*/
void Attacked (Buildings *B);
/*
{I.S Building defined}
{F.S state Attacked based on defenses}
*/
void Occupy (Buildings *B);
/*
{I.S Building not occupied or owner = 0}
{F.S Building Occupied owner = 1 || 2}
*/