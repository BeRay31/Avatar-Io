#ifndef __QUEUE_H__
#define __QUEUE_H__
//preprocessors

#include "List.h"
typedef struct 
{
    address Head;
    address Tail;
}Queue;

bool QIsEmpty(Queue Q);
/*
{I.S Q defined}
{F.S True if Q Empty && False if Q not Empty}
*/

void QCreateEmpty (Queue *Q);
/*
{I.S Anything}
{F.S Q created and Q empty}
*/

int QNbElmt(Queue Q);
/*
{I.S Anything}
{F.S Return Number Element of Q}
*/

void QAdd (Queue *Q,Buildings X);
/*
{I.S Q defined}
{F.S Elmt of Q ++ Tail = new Elmt}
*/

void QDel (Queue *Q,Buildings *X);
/*
{I.S Q defined }
{F.S Head deleted or 1st element deleted}
*/

void CopyQueue(Queue *Q,Queue TempQ);
/*
{I.S TempQ and Q defined}
{F.S Q = TempQ}
*/

#endif