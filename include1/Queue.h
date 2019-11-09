#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "Skills.h"
#include <stdlib.h>
#include <stdbool.h>
//preprocessor
#define MaxElQueue 10
typedef struct sElmtlist *address;  //define *address as struct tElmtList
typedef struct sElmtlist {  //define ELmtList as Struct tElmtList
	Skill info;
	address next;
} ElmtQueue;
typedef struct {
	address Head,Tail;
} Queue;

address AllocateQ (Skill S);
/*
{I.S anything}
{F.S S alocated}
*/
int NbQElmt (Queue Q);
/*
{I.S Q Defined}
{F.S Return NbELmt}
*/

bool IsQEmpty (Queue Q);
/*
{I.S Q defined}
{F.S True if Q Empty && False if Q not Empty}
*/

bool IsQFull (Queue Q);
/*
{I.S Q Defined}
{F.S True If ElmtQ = MaxEl}
*/
void QCreateEmpty(Queue *Q);
/*
{I.S Anything}
{F.S Q created and Q empty}
*/
 
void QAddElmt (Queue *Q, Skill S);
/*
{I.S Q defined}
{F.S Elmt of Q ++ Tail = new Elmt}
*/

void QDelElmt (Queue *Q, Skill *S);
/*
{I.S Q defined }
{F.S Head deleted or 1st element deleted}
*/

#endif