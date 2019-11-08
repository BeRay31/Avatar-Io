#include "../include1/Stack.h"
//UNDO Mech

void SCreateEmpty(Stack *S)
{
    (*S).top = NULL;
}
/*
{I.S Anything}
{F.S Stack S defined}
*/

stackAddress Sallocate (infotype X)
{
    stackAddress S;
    S = (stackAddress) malloc (sizeof(StackElmt));
    if (S != NULL)
    {
        S->info = X;
        S->next = NULL;
    }
    else
    {
        S = NULL;
    }
    return S;
}
/*
{I.S Anything}
{F.S X allocated as StackAddress}
*/ 


void Push (Stack *S,infotype X)
{
    stackAddress NewElmt;
    NewElmt = Sallocate(X);
    NewElmt->next = (*S).top;
    (*S).top = NewElmt;
}
/*
{I.S Anything}
{F.S Stack Pushed with new Elmt X}
*/

void Pop (Stack *S,infotype *X)
{
    if ((*S).top != NULL)
    {
        *X = (*S).top->info;
        (*S).top = (*S).top->next;
    }
}
/*
{I.S Anything}
{F.S Top Elmt of Stack Popped and Saved in X}
*/
