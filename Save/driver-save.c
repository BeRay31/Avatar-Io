#include <stdio.h>
#include "../Booelan/boolean.h"
#include "../LoadInfoAwal/loadinfoawal.h"
#include "save.h"
#include "../Queue/Queue.h"

int main()
{
    /*
    gcc -o test-save driver-save.c mesinkar.c mesinkata.c loadinfoawal.c save.c Queue.c matriks.c dinamicArr.c
    */
    int n, m, nbangunan;
    TabBuildings b;
    MATRIKS mgraf;
    Queue q1, q2;
    int turn = 1;
    CreateEmptyQ(&q1, 0); CreateEmptyQ(&q2, 0);
    GetInfoDariFile(&n, &m, &nbangunan, &b, &mgraf);
    Save(b, n, m, nbangunan, q1, q2, turn);
}