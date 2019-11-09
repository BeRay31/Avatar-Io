#include "../include1/List.h"
//IMPLEMENTATION

//Save list of index Player Buildings

address AllocateL (int X)
{
    address P;
    P = (address)malloc(sizeof(BElmtList));
    if (P!=NULL)
    {
        P->info = X;
        P->next = NULL;
        return P;
    }
    else
    {
        return NULL;
    }
}
/*
{I.S Anything}
{F.S X allocated}
*/

void CreateEmptyL (List *L)
{
   (*L).First = NULL ;
}
/*
{I.S Anything}
{F.S Building Defined}
*/
boolean IsEmpty (List L){  
	return L.First==NULL;
}

void InsertFirst (List *L, address P)
{
    P->next = (*L).First;
    (*L).First = P;
}
/*
{I.S List defined}
{F.S First Elmt B is P}
*/

void InsertAfter (List *L, address P, address Prec)
{
   P->next = Prec->next;
   Prec->next = P; 
}
/*
{I.S List defined}
{F.S Elmt after Prec is P}
*/

void DelFirst (List *L, address *P)
{
    *P = (*L).First;
    (*L).First = (*L).First->next;
}
/*
{I.S List defined}
{F.S First element of List deleted and saved in P} 
*/
void DelP (List *L, address *Pdel, address P)
{
    if (P == (*L).First)
    {
        DelFirst(L,Pdel);
    }
    else
    {
        address delElmt;
        *Pdel = P;
        delElmt = (*L).First;
        while (delElmt->next != P)
        {
            delElmt = delElmt->next;
        }
        delElmt->next = P->next;
    }
}
/*
{I.S List Defined}
{F.S Elmt  Prec Deleted and saved in Pdel}
*/
void InsertLast (List *L, address P)
{
    address Last;
    if (!IsEmpty(*L))
    {
        Last = (*L).First;
        while (Last->next!=NULL)
        {
            Last = Last->next;
        }
        (P)->next = Last->next;
        Last->next = P;
    }
    else
    {
        InsertFirst(L,P);
    }
}
/*
{I.S List Defined}
{F.S Last Elmt of List updated by P}
*/
address Search (List L, int X)
{
    address P;
    P = L.First;
    if (P==NULL)
    {
        return NULL;
    }
    else
    {
        while (((P)->info != X) && (P != NULL))
        {
            P = P->next;
            if (P == NULL)
            {
                return NULL;
            }
        }
        return P;
    }
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */