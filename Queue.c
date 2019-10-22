#include "Queue.h"

//IMPLEMENTATION
bool QIsEmpty(Queue Q)
{
    return ((Q).Head == NULL && ((Q).Tail==NULL));
}
/*
{I.S Q defined}
{F.S True if Q Empty && False if Q not Empty}
*/

void QCreateEmpty (Queue *QAdd)
{
    (*QAdd).Head = NULL;
    (*QAdd).Tail = NULL;
}
/*
{I.S Anything}
{F.S Q created and Q empty}
*/

int QNbElmt(Queue Q)
{
    address CElmt;
    int nBElmt = 0;
    if (Q.Head == NULL)
    {
        return nBElmt;
    }
    else
    {
        if ((Q).Head == (Q).Tail)
        {
            nBElmt ++;
            return nBElmt;
        }
        else
        {
            CElmt = (Q).Head;
            while (CElmt != (Q).Tail)
            {
                nBElmt++;
                CElmt = Next(CElmt);
            }
            nBElmt++;
            return nBElmt;
        }
    }
        
}
/*
{I.S Anything}
{F.S Return Number Element of Q}
*/

void QAdd (Queue *Q,Buildings X)
{
    address Elmt,NewElmt;
    NewElmt = Alokasi (X);
    if (QIsEmpty(*Q))
    {
        (*Q).Head = NewElmt;
        (*Q).Tail = NewElmt;
    }
    else
    {
        Next((*Q).Tail) = NewElmt;
    }
     
}
/*
{I.S Q defined}
{F.S Elmt of Q ++ Tail = new Elmt}
*/

void QDel (Queue *Q,Buildings *X)
{
    if ((*Q).Head == (*Q).Tail)
    {
        *X = (*Q).Head -> info;
        (*Q).Head = NULL;
        (*Q).Tail = NULL;
    }
    else
    {
        *X = (*Q).Head -> info;
        (*Q).Head = Next ((*Q).Head);
    }
}
/*
{I.S Q defined }
{F.S Head deleted or 1st element deleted}
*/
