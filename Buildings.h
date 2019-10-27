#ifndef __BUILDINGS_H__
#define __BUILDINGS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxArmies 1000000

typedef struct{
    unsigned short int owner; //owner 1 or 2
    int armies; // total army in building
    unsigned short int level; //building's level 1 2 3 4
    int incArmy; //increment army depends on levels (A) / turn
    int maxArmyOnBuildings; //Max Army in Building (M)
    bool defenses; //defenses status yes = true , no = false
    int minArmiesToOccupy; //precondition to occupy an free building (total army) auto to level 1
    char buildingsType; //
    int buildingsIndex; //
}Buildings;
//data structures for buildings

//functions and procedures

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
void Attacked (Buildings *B, Buildings *BL,int NArmies);
/*
{I.S Building defined}
{F.S state Attacked based on defenses}
*/
void Occupy (Buildings *B);
/*
{I.S Building not occupied or owner = 0}
{F.S Building Occupied owner = 1 || 2}
*/
#endif
