#ifndef __LIST_H__
#define __LIST_H__

#include "Buildings.h"
// LInked List for Buildings
//TYPEDEF
typedef Buildings infotype;
typedef struct bElmtlist *buildingAddress;  //define *address as struct tElmtList
typedef struct bElmtlist {  //define ELmtList as Struct tElmtList
	infotype info;
	buildingAddress next;
} BElmtList;
typedef struct {
	buildingAddress First;
} ListB;

buildingAddress AllocateB (infotype X);
/*
{I.S Anything}
{F.S X allocated}
*/

void CreateEmptyB (ListB *L);
/*
{I.S Anything}
{F.S Building Defined}
*/

void InsertFirst (ListB *L, buildingAddress P);
/*
{I.S List defined}
{F.S First Elmt B is P}
*/

void InsertAfter (ListB *L, buildingAddress P, buildingAddress Prec);
/*
{I.S List defined}
{F.S Elmt after Prec is P}
*/

void DelFirst (ListB *L, buildingAddress *P);
/*
{I.S List defined}
{F.S First element of List deleted and saved in P} 
*/
void DelAfter (ListB *L, buildingAddress *Pdel, buildingAddress Prec);
/*
{I.S List Defined}
{F.S Elmt After Prec Deleted and saved in Pdel}
*/

#endif