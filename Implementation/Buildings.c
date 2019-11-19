#include "../include1/Buildings.h"

void CreateBuildings (Buildings *B,char type)
/*
{I.S anything}
{F.S Building Created Based on Type}
*/
{
	
	if(type=='C'){
		(*B).buildingsIndex = 0;
		(*B).buildingsType = type;
		(*B).level = 1;
		(*B).owner = 0;
		(*B).incArmy = 10;
		(*B).maxArmyOnBuildings = 40;
		(*B).defenses = false;
		(*B).minArmiesToOccupy = 40;
		(*B).armies = 0;
	}
	else if (type=='T'){
		(*B).buildingsIndex = 0;
		(*B).buildingsType = type;
		(*B).level = 1;
		(*B).owner = 0;
		(*B).incArmy = 5;
		(*B).maxArmyOnBuildings = 20;
		(*B).defenses = true;
		(*B).minArmiesToOccupy = 30;
		(*B).armies = 0;
	}
	else if(type=='F'){
		(*B).buildingsIndex = 0;
		(*B).buildingsType = type;
		(*B).level = 1;
		(*B).owner = 0;
		(*B).incArmy = 10;
		(*B).maxArmyOnBuildings = 20;
		(*B).defenses = false;
		(*B).minArmiesToOccupy = 80;
		(*B).armies = 0;
	}
	else if(type=='V'){
		(*B).buildingsIndex = 0;
		(*B).buildingsType = type;
		(*B).level = 1;
		(*B).owner = 0;
		(*B).incArmy = 5;
		(*B).maxArmyOnBuildings = 20;
		(*B).defenses = false;
		(*B).minArmiesToOccupy = 20;
		(*B).armies = 0;
	}
	else if(type==' '){
		(*B).buildingsIndex = 0;
		(*B).buildingsType = type;
		(*B).level = 0;
		(*B).owner = 0;
		(*B).incArmy = 0;
		(*B).maxArmyOnBuildings = 0;
		(*B).defenses = false;
		(*B).minArmiesToOccupy = 0;
		(*B).armies = 0;
	}
}

void LevelUp (Buildings *B)
/*
{I.S level 1 2 3}
{F.S level++ and <=4}
*/
{
	if((*B).level <4 && (*B).armies>=((*B).maxArmyOnBuildings/2)){
		(*B).armies -= ((*B).maxArmyOnBuildings/2);
		if((*B).buildingsType == 'C'){
			(*B).incArmy += 5;
			(*B).maxArmyOnBuildings += 20;
			(*B).minArmiesToOccupy = 0;
			(*B).level ++;
			printf("Level Castle-mu meningkat menjadi %d!\n", (*B).level);		
		}	
		else if((*B).buildingsType == 'T'){
			if((*B).level==1){
				(*B).incArmy += 5;
			}
			else{
				(*B).incArmy += 10;	
			}
			(*B).maxArmyOnBuildings += 10;
			(*B).minArmiesToOccupy = 0;
			(*B).level ++;
			printf("Level Tower-mu meningkat menjadi %d!\n", (*B).level);
		}
		else if((*B).buildingsType == 'F'){
			(*B).incArmy += 10;
			(*B).maxArmyOnBuildings += 20;
			(*B).minArmiesToOccupy = 0;	
			if((*B).level > 1)
			{
				(*B).defenses = true;
			}
			(*B).level ++;
			printf("Level Fort-mu meningkat menjadi %d!\n", (*B).level);
		}
		else if((*B).buildingsType == 'V'){
			(*B).incArmy += 5;
			(*B).maxArmyOnBuildings += 10;
			(*B).minArmiesToOccupy = 0;	
			(*B).level ++;
			printf("Level Village-mu meningkat menjadi %d!\n", (*B).level);
		}
	}
	else{
		if((*B).buildingsType == 'C'){
			printf("Jumlah pasukan Castle kurang untuk level up");	
		}
		else if((*B).buildingsType == 'F'){
			printf("Jumlah pasukan Fort kurang untuk level up");	
		}
		else if((*B).buildingsType == 'T'){
			printf("Jumlah pasukan Tower kurang untuk level up");	
		}
		else if((*B).buildingsType == 'V'){
			printf("Jumlah pasukan Village kurang untuk level up");	
		}
	}
}
void IncTroops (Buildings *B)
/*
{I.S Anything}
{F.S Total Army incremented by (A)}
*/
{
	if((*B).owner!=0){  
		(*B).armies += (*B).incArmy;
	}
}
void Attack (Buildings *B, Buildings *BL, int Narmies)//*BL = Target
/*
{I.S Building defined, }
{F.S state Attack based on defenses}
*/
{
	POINT positionBL;
	char typenewBL;
	int tempArmies = 0;
	int tempIndex;
	int nerfedNarmies;
	if((*BL).defenses = false)
	{
		if(Narmies>=(*BL).armies)
		{
			(*B).armies -= Narmies;//decrement armies
			tempArmies = Narmies - (*BL).armies; //building(*BL)new armies
			positionBL.X = (*BL).position.X;
			positionBL.Y = (*BL).position.Y;
			tempIndex = (*BL).buildingsIndex;
			typenewBL = (*BL).buildingsType;
			CreateBuildings(BL,typenewBL);
			(*BL).owner = (*B).owner;
			(*BL).position = positionBL;
			(*BL).armies = tempArmies;
			(*BL).buildingsIndex = tempIndex;
			(*BL).minArmiesToOccupy = 0;//not defined building has been owned by somenone
		}
		else
		{
			(*B).armies -= Narmies;
			(*BL).armies -= Narmies;
			printf("Bangunan gagal direbut.\n");
		}
	}	
	else
	{
		nerfedNarmies = Narmies*3/4;
		if(nerfedNarmies>=(*BL).armies)
		{
			(*B).armies -= Narmies;//decrement armies
			tempArmies = nerfedNarmies - (*BL).armies; //building(*BL)new armies
			if(tempArmies >= 0)
			{
				tempArmies = tempArmies*4/3;
			}
			positionBL.X = (*BL).position.X;
			positionBL.Y = (*BL).position.Y;
			tempIndex = (*BL).buildingsIndex;
			typenewBL = (*BL).buildingsType;
			CreateBuildings(BL,typenewBL);
			(*BL).owner = (*B).owner;
			(*BL).position = positionBL;
			(*BL).armies = tempArmies;
			(*BL).buildingsIndex = tempIndex;
			(*BL).minArmiesToOccupy = 0;//not defined building has been owned by somenone			
		}
		else
		{
			(*B).armies -= Narmies;
			(*BL).armies -= nerfedNarmies;
			printf("Bangunan gagal direbut.\n");
		}
	}
}
void Occupy (Buildings *B,Buildings *BL,int Narmies)//BL target
/*
{I.S Building not occupied or owner = 0}
{F.S Building Occupied owner = 1 || 2}
*/
{
	POINT positionBL;
	char typenewBL;
	int tempArmies = 0;
	int tempIndex;
	int nerfedNarmies;
	if((*BL).defenses = false)
	{
		if(Narmies>=(*BL).minArmiesToOccupy)
		{
			(*B).armies -= Narmies;//decrement armies
			tempArmies = Narmies - (*BL).minArmiesToOccupy; //building(*BL)new armies
			positionBL.X = (*BL).position.X;
			positionBL.Y = (*BL).position.Y;
			tempIndex = (*BL).buildingsIndex;
			typenewBL = (*BL).buildingsType;
			CreateBuildings(BL,typenewBL);
			(*BL).owner = (*B).owner;
			(*BL).position = positionBL;
			(*BL).armies = tempArmies;
			(*BL).buildingsIndex = tempIndex;
			(*BL).minArmiesToOccupy = 0;//not defined building has been owned by somenone
		}
		else
		{
			(*B).armies -= Narmies;
			(*BL).minArmiesToOccupy -= Narmies;
			printf("Bangunan gagal dikuasai.\n");
		}
	}	
	else
	{
		nerfedNarmies = Narmies*3/4;
		if(nerfedNarmies>=(*BL).minArmiesToOccupy)
		{
			(*B).armies -= Narmies;//decrement armies
			tempArmies = nerfedNarmies - (*BL).minArmiesToOccupy; //building(*BL)new armies
			if(tempArmies >= 0)
			{
				tempArmies = tempArmies*4/3;
			}
			positionBL.X = (*BL).position.X;
			positionBL.Y = (*BL).position.Y;
			tempIndex = (*BL).buildingsIndex;
			typenewBL = (*BL).buildingsType;
			CreateBuildings(BL,typenewBL);
			(*BL).owner = (*B).owner;
			(*BL).position = positionBL;
			(*BL).armies = tempArmies;
			(*BL).buildingsIndex = tempIndex;
			(*BL).minArmiesToOccupy = 0;//not defined building has been owned by somenone			
		}
		else
		{
			(*B).armies -= Narmies;
			(*BL).minArmiesToOccupy -= nerfedNarmies;
		}
	}	
}
void Move (Buildings *B, Buildings *B2, int Narmies)
{
	(*B).armies -= Narmies;
	(*B2).armies += Narmies;//10 pasukan dari Tower (1,13) telah berpindah ke Village (1,9) 
	if((*B).buildingsType == 'C')
	{
		if((*B2).buildingsType == 'T')
		{
			printf("%d pasukan dari Castle (%d,%d) telah berpindah ke Tower (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
		else if((*B2).buildingsType == 'F')
		{
			printf("%d pasukan dari Castle (%d,%d) telah berpindah ke Fort (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
		else if((*B2).buildingsType == 'V')
		{
			printf("%d pasukan dari Castle (%d,%d) telah berpindah ke Village (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
	}
	else if ((*B).buildingsType == 'T')
	{
		if((*B2).buildingsType == 'C')
		{
			printf("%d pasukan dari Tower (%d,%d) telah berpindah ke Castle (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
		else if((*B2).buildingsType == 'F')
		{
			printf("%d pasukan dari Tower (%d,%d) telah berpindah ke Fort (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
		else if((*B2).buildingsType == 'V')
		{
			printf("%d pasukan dari Tower (%d,%d) telah berpindah ke Village (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
	}
	else if ((*B).buildingsType == 'F')
	{
		if((*B2).buildingsType == 'C')
		{
			printf("%d pasukan dari Fort (%d,%d) telah berpindah ke Castle (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
		else if((*B2).buildingsType == 'T')
		{
			printf("%d pasukan dari Fort (%d,%d) telah berpindah ke Tower (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
		else if((*B2).buildingsType == 'V')
		{
			printf("%d pasukan dari Fort (%d,%d) telah berpindah ke Village (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
	}
	else if ((*B).buildingsType == 'V')
	{
		if((*B2).buildingsType == 'C')
		{
			printf("%d pasukan dari Village (%d,%d) telah berpindah ke Castle (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
		else if((*B2).buildingsType == 'F')
		{
			printf("%d pasukan dari Village (%d,%d) telah berpindah ke Fort (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
		else if((*B2).buildingsType == 'T')
		{
			printf("%d pasukan dari Village (%d,%d) telah berpindah ke Tower (%d,%d)",Narmies,(*B).position.X,(*B).position.Y,(*B2).position.X,(*B2).position.Y);
		}
	}
}
/*
{I.S Anything}
{F.S Narmies from B moved into B2}
*/