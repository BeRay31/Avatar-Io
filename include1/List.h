#ifndef __LIST_H__
#define __LIST_H__

#include "Buildings.h"
//TYPEDEF
typedef struct bElmtlist *address;  //define *address as struct tElmtList
typedef struct bElmtlist {  //define ELmtList as Struct tElmtList
	int info;
	address next;
} BElmtList;
typedef struct {
	address First;
} List;

address AllocateL (int X);
/*
{I.S Anything}
{F.S X allocated}
*/

void CreateEmptyL (List *L);
/*
{I.S Anything}
{F.S Building Defined}
*/
boolean IsEmpty (List L);

void InsertFirst (List *L, address P);
/*
{I.S List defined}
{F.S First Elmt B is P}
*/

void InsertAfter (List *L, address P, address Prec);
/*
{I.S List defined}
{F.S Elmt after Prec is P}
*/
void DelP (List *L, address *Pdel, address P);

void DelFirst (List *L, address *P);
/*
{I.S List defined}
{F.S First element of List deleted and saved in P} 
*/
void DelAfter (List *L, address *Pdel, address Prec);
/*
{I.S List Defined}
{F.S Elmt After Prec Deleted and saved in Pdel}
*/
void InsertLast (List *L, address P);
/*
{I.S List Defined}
{F.S Last Elmt of List updated by P}
*/
address Search (List L, int X);
#endif
