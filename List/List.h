#ifndef __LIST_H__
#define __LIST_H__

#include "../Buildings/Buildings.h"
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
/*
{I.S  List Defined}
{F.S  Return True if is empty}
*/
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
/*
{I.S List DEfined}
{F.S Delete address P on List}
*/
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
/*
{I.S List Defined}
{F.S Return address list that have info X}
*/
void CopyList(List Lsrc, List *Ldest);
/*
{I.S Lsrc Defined}
{F.S List copied to Ldest}
*/
void PrintInfo (List L);
/*
{I.S List Defined}
{F.S List printed}
*/
#endif
