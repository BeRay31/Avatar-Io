#include "Buildings.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    Buildings B;
    CreateBuildings(&B,'C');
    //Create Buildings
    printf("type:%c,level:%d,incArmy:%d,MaxArmy:%d,MinArmiestoOccupy:%d\n",B.buildingsType,B.level,B.incArmy,B.maxArmyOnBuildings,B.minArmiesToOccupy);
    //------------------------------------------------
    JustLvlUp(&B);
    B.armies = 40;
    //JstLevelUp
    printf("Level:%d, Armies:%d \n",B.level,B.armies);
    //------------------------------------------------
    LevelUp(&B);
    //LevelUP
    printf("Level:%d,Armies:%d\n",B.level,B.armies);
    LevelUp(&B);
    printf("Tidak Cukup\n");
    //-----------------------------------------------
    IncTroops(&B);
    //IncTroops
    printf("Armies:%d\n",B.armies);
    //-----------------------------------------------
    Buildings Target;
    CreateBuildings(&Target,'T');
    B.owner = 1;
    Target.owner = 2;
    printf("Attacking...\n");
    printf("B->Armies:%d,owner:%d\n",B.armies,B.owner);
    printf("Btarget->Armies:%d,owner:%d\n",B.armies,B.owner);
    Target.armies = 50;
    Attack(&B,&Target,10);
    //ATTACK
    printf("After ...");
    printf("B->Armies:%d,owner:%d\n",B.armies,B.owner);
    printf("Btarget->Armies:%d,owner:%d\n",B.armies,B.owner);
    //--------------------------------------------
    B.owner = 1;
    B.armies = 50;
    Target.owner = 0;
    Target.armies = 10;
    printf("Occupying......\n");
    printf("B->Armies:%d,owner:%d\n",B.armies,B.owner);
    printf("Btarget->Armies:%d,owner:%d\n",B.armies,B.owner);
    Occupy(&B,&Target,30);
    //Occupying
    printf("After.....\n");
    printf("B->Armies:%d,owner:%d\n",B.armies,B.owner);
    printf("Btarget->Armies:%d,owner:%d\n",B.armies,B.owner);
    //------------------------------------------------------
    B.owner = 1;
    Target.owner = 1;
    B.armies = 20;
    Target.armies = 20;
    printf("Moving.....\n");
    printf("B->Armies:%d,owner:%d\n",B.armies,B.owner);
    printf("Btarget->Armies:%d,owner:%d\n",B.armies,B.owner);
    Move(&B,&Target,20);
    printf("After...\n");
    printf("B->Armies:%d,owner:%d\n",B.armies,B.owner);
    printf("Btarget->Armies:%d,owner:%d\n",B.armies,B.owner);
    //-------------------------------------------------------
    return 0;
}