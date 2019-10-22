#ifndef __LIST_H__
#define __LIST_H__

#include "Buildings.h"

//TYPEDEF
typedef struct tElmtlist *address;
typedef struct tElmtlist {
	Buildings info;
	address next;
} ElmtList;
typedef struct {
	address First;
} List;
//SELECTOR
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

address Alokasi (Buildings X); //pastiin nextnya NULL

void InsertFirst (List *L, address P);

void InsertAfter (List *L, address P, address Prec);

void DelFirst (List *L, address *P);

void DelAfter (List *L, address *Pdel, address Prec);

#endif