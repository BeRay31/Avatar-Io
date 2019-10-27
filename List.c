#include "List.h"
//IMPLEMENTATION

buildingAddress AllocateB (infotype X)
{
    buildingAddress P;
    P = (buildingAddress*)malloc(sizeof(BElmtList));
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

void CreateEmptyB (ListB *L)
{
   (*L).First = NULL ;
}
/*
{I.S Anything}
{F.S Building Defined}
*/

void InsertFirst (ListB *L, buildingAddress P)
{
    if((*L).First ==NULL)
    {
        P->next = NULL;  
        (*L).First = P;
    }
    else
    {
        P->next = (*L).First->next;
        (*L).First = P;        
    }    
}
/*
{I.S List defined}
{F.S First Elmt B is P}
*/

void InsertAfter (ListB *L, buildingAddress P, buildingAddress Prec)
{
   P->next = Prec->next;
   Prec->next = P; 
}
/*
{I.S List defined}
{F.S Elmt after Prec is P}
*/

void DelFirst (ListB *L, buildingAddress *P)
{
    *P = (*L).First;
    (*L).First = (*L).First->next;
}
/*
{I.S List defined}
{F.S First element of List deleted and saved in P} 
*/
void DelP (ListB *L, buildingAddress *Pdel, buildingAddress P)
{
    if (P == (*L).First)
    {
        DelFirst(L,Pdel);
    }
    else
    {
        buildingAddress delElmt;
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
