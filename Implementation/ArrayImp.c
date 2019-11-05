
#include <stdio.h>
#include "../include1/ArrayImp.h"
void MakeEmpty (TabInt * T)
{
	int i;

	for (i = IdxMin ; (i <= (IdxMax-IdxMin+1)) ; i++){
		Elmt(*T, i).position.X = -999;
	}
}
/*
{I.S Anything}
{F.S Make Empty Array}
*/

int NbOfBuildings (TabInt T)

{
	int i;
	int count = 0;
	for (i = IdxMin ; (i <= (IdxMax-IdxMin+1)) ; i++){
		if(Elmt(T, i).position.X != -999){
			count++;
		}
	}
	return count;
}
/*
{I.S T defined}
{F.S return NBElmt of T}
*/

boolean IsPointBuilding (TabInt T, int x, int y)

{
	int i;
	for (i = IdxMin ; (i <= (IdxMax-IdxMin+1)) ; i++){
		if(Elmt(T, i).position.X == x && Elmt(T, i).position.Y == y){
			return true;
		}
	}
	return false;
}
/*
{I.S T defined}
{F.S return true if x,y are position of Building}
*/

void AddBuilding(TabInt *T, Buildings B){
	int i;
	for (i = IdxMin ; (i <= (IdxMax-IdxMin+1)) ; i++){
		if(Elmt(*T, i).position.X == -999){
			break;
		}
	}
	Elmt(*T,i).position.X = B.position.X;
	Elmt(*T,i).position.Y = B.position.Y;
	Elmt(*T,i).owner = B.owner;
	Elmt(*T,i).armies = B.armies;
	Elmt(*T,i).defenses = B.defenses;
	Elmt(*T,i).buildingsType = B.buildingsType;
	Elmt(*T,i).level = 1;
}
/*
{I.S T defined}
{F.S Added new elmt on T}
*/