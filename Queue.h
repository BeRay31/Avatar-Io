#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "Skills.h"
#include <stdlib.h>
#include <stdbool.h>
//preprocessor

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

bool IsQEmpty (Queue Q);
/*
{I.S Q defined}
{F.S True if Q Empty && False if Q not Empty}
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