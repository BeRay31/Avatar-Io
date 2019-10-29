
#include "ArrayImp.h"
#include <stdio.h>
void MakeEmpty (TabInt * T)
{
	int i;

	for (i = IdxMin ; (i <= (IdxMax-IdxMin+1)) ; i++){
		Elmt(*T, i).X = -999;
	}
}

int NbOfBuildings (TabInt T)

{
	int i;
	int count = 0;
	for (i = IdxMin ; (i <= (IdxMax-IdxMin+1)) ; i++){
		if(Elmt(T, i).X != -999){
			count++;
		}
	}
	return count;
}

boolean IsPointBuilding (TabInt T, int x, int y)

{
	int i;
	for (i = IdxMin ; (i <= (IdxMax-IdxMin+1)) ; i++){
		if(Elmt(T, i).X == x && Elmt(T, i).Y == y){
			return true;
		}
	}
	return false;
}

void AddBuilding(TabInt *T, int owner, int armies, boolean defenses, char type, int x, int y){
	int i;
	for (i = IdxMin ; (i <= (IdxMax-IdxMin+1)) ; i++){
		if(Elmt(*T, i).X == -999){
			break;
		}
	}
	Elmt(*T,i).X = x;
	Elmt(*T,i).Y = y;
	Elmt(*T,i).owner = owner;
	Elmt(*T,i).armies = armies;
	Elmt(*T,i).defenses = defenses;
	Elmt(*T,i).buildingsType = type;
	Elmt(*T,i).level = 1;
	if(type == 'C'){
		Elmt(*T,i).minArmiesToOccupy = 40;
		Elmt(*T,i).incArmy = 10;
	}
	else if(type == 'F'){
		Elmt(*T,i).minArmiesToOccupy = 80;
		Elmt(*T,i).incArmy = 10;
	}
	else if(type == 'T'){
		Elmt(*T,i).minArmiesToOccupy = 30;
		Elmt(*T,i).incArmy = 5;
	}
	else if(type == 'V'){
		Elmt(*T,i).minArmiesToOccupy = 20;
		Elmt(*T,i).incArmy = 5;
	}
}