#include "../include1/Queue.h"
//IMPLEMENTATION

//SKILL Mech

Saddress AllocateQ (Skill S)
{
    Saddress P;
    P = (Saddress)malloc(sizeof(ElmtQueue));
    if (P != NULL)
    {
        P->info = S;
        P->next = NULL;
        return P;
    }
    else
    {
        return NULL;
    }
}
/*
{I.S anything}
{F.S S alocated}
*/

int NbQElmt (Queue Q)
{
    int x = 0;
    Saddress P;
    P = Q.Head;
    while (P != Q.Tail)
    {
        x++;
        P = P->next;
    }
    return x;
}
/*
{I.S Q Defined}
{F.S Return NbELmt}
*/


bool IsQEmpty (Queue Q)
{
    return ((Q.Head == NULL)&&(Q.Tail == NULL));
}
/*
{I.S Q defined}
{F.S True if Q Empty && False if Q not Empty}
*/

bool IsQFull (Queue Q)
{
    return (NbQElmt(Q)==MaxElQueue);
}
/*
{I.S Q Defined}
{F.S True If ElmtQ = MaxEl}
*/

void QCreateEmpty(Queue *Q)
{
    (*Q).Head = NULL;
    (*Q).Tail = NULL;
}
/*
{I.S Anything}
{F.S Q created and Q empty}
*/

void QAddElmt (Queue *Q, Skill S)
{
    Saddress newSkill;
    if (!IsQFull(*Q))
    {
        newSkill = Allocate (S);
        if (IsQEmpty(*Q))
        {
            (*Q).Head = newSkill;
            (*Q).Tail = newSkill;        
        }
        else
        {
            (*Q).Tail->next = newSkill;
            (*Q).Tail = (*Q).Tail->next;
        }
    }
}
/*
{I.S Q defined}
{F.S Elmt of Q ++ Tail = new Elmt}
*/
void QDelElmt (Queue *Q, Skill *S)
{
    if ((*Q).Head == (*Q).Tail)
    {
        *S = (*Q).Head ->info;
        (*Q).Head = NULL;
        (*Q).Tail = NULL;
    }
    else
    {
        *S = (*Q).Head->info;
        (*Q).Head = (*Q).Head->next; 
    }
}
/*
{I.S Q defined }
{F.S Head deleted or 1st element deleted}
*/