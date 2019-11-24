#include <stdio.h>
#include "../include1/boolean.h"
#include "../include1/loadinfoawal.h"
#include "../include1/save.h"
#include "../include1/Queue.h"

int main()
{
    /*
    List P1Buildings,P2Buildings;
    BuildMap Peta;
    int n,m,nbuildings;
    TabBuildings arrBuildings;
    MATRIKS graf;
    Stack S;
    */
    int n, m, nbangunan;
    TabBuildings b;
    MATRIKS mgraf;
    Queue q1, q2;
    int turn = 1;
    CreateEmptyQ(&q1, 0); CreateEmptyQ(&q2, 0);
    GetInfoDariFile(&n, &m, &nbangunan, &b, &mgraf);
    Save(b, n, m, nbangunan, q1, q2, turn);
    return 0;
}