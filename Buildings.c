#include "Buildings.h"

void CreateBuildings (Buildings *B,char type)
/*
{I.S anything}
{F.S Building Created Based on Type}
*/
{
	unsigned short int P;
	if(type=='C'){ //Castle Type
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
	else if (type=='T'){ //Tower Type
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
	else if(type=='F'){ //Fottres Type
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
	else if(type=='V'){ //Vilage Type
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
	else if(type==' '){ //Blank Type
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
	if( ((*B).level < 4) && ((*B).armies>=((*B).maxArmyOnBuildings/2)) && ((*B).owner!=0)) //Check Level
	{
		(*B).armies -= ((*B).maxArmyOnBuildings/2);
		if((*B).buildingsType == 'C') //LevelUp Castle
		{
			(*B).incArmy += 5;
			(*B).maxArmyOnBuildings += 20;
			(*B).minArmiesToOccupy = -999;		
		}	
		else if((*B).buildingsType == 'T') //LevelUp Tower
		{
			if((*B).level==1){
				(*B).incArmy += 5;
			}
			else{
				(*B).incArmy += 10;	
			}
			(*B).maxArmyOnBuildings += 10;
			(*B).minArmiesToOccupy = -999;
		}
		else if((*B).buildingsType == 'F') //LevelUp Fotress
		{
			(*B).incArmy += 10;
			(*B).maxArmyOnBuildings += 20;
			(*B).minArmiesToOccupy = -999;	
			if((*B).level > 1){
				(*B).defenses = true;
			}
		}
		else if((*B).buildingsType == 'V') //LevelUp Village
		{
			(*B).incArmy += 5;
			(*B).maxArmyOnBuildings += 10;
			(*B).minArmiesToOccupy = -999;	
		}
		(*B).level ++;

	}
	
}
void IncTroops (Buildings *B)
/*
{I.S Anything}
{F.S Total Army incremented by (A)}
*/
{
	(*B).armies += (*B).incArmy;
}
void Attacked (Buildings *B, Buildings *BL, int Narmies) //not verified
/*
{I.S Building defined, }
{F.S state Attacked based on defenses}
*/
{
	int army;  

	(*BL).armies -= Narmies; //jumlah pasukan penyerang bberkurang sebanyak narmies
	//jika bangunan yang diserang (B) tidak bukan pemilik lawan
	if((*B).owner==0){
		
		(*B).minArmiesToOccupy -= Narmies;
		if ((*B).minArmiesToOccupy=0){
			(*B).owner = (*BL).owner; 
			(*B).armies = 0; 
		}
		else if((*B).minArmiesToOccupy < 0){
			(*B).owner = (*BL).owner; 
			(*B).armies = -1*((*B).minArmiesToOccupy);

		}
	}
	//jika bangunan yang diserang (B) pemilik lawan
	else{
		if((*B).defenses){
			(*B).armies -= (Narmies*3/4);
		}
		else{
			(*B).armies -= Narmies;
		}
		
		

		if((*B).armies <= 0){
			army = -1*((*B).armies);
			CreateBuildings(B, (*B).buildingsType); //bangunan dirubah ke kondisi level 1
			(*B).owner = (*BL).owner;//kepemilikan di rubah
			
			(*B).armies += army; 
		}

	}
	
}
void Occupy (Buildings *B)
/*
{I.S Building not occupied or owner = 0}
{F.S Building Occupied owner = 1 || 2}
*/
{
	
}