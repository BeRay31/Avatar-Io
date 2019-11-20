#ifndef __SKILL_H__
#define __SKILL_H__

#include "Queue.h"
#include "dinamicArr.h"
#include "Buildings.h"
//SKILL ALGORITHM
void InstantUpgrade (TabBuildings *ArrB,int player);

void Shield(TabBuildings *ArrB,int player);

void ExtraTurn();

void AttackUp(TabBuildings *ArrB,int player);

void CriticalHit(TabBuildings *ArrB,int player);

void InstantReinforcement(TabBuildings *ArrB, int player);

void Barrage(TabBuildings *ArrB, int player);

#endif