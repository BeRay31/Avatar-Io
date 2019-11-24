#ifndef LOADINFOAWAL_H
#define LOADINFOAWAL_H

#include "../Booelan/boolean.h"
#include "../DinamicArr/dinamicArr.h"
#include "../mesinkata/mesinkata.h"
#include "../Matriks/matriks.h"
#include "../Buildings/Buildings.h"


/* KONSTRUKTOR ARRAY PENYIMPAN INFO BANGUNAN */
/*
typedef struct {
  Buildings *T;
  int MaxEl; 
} BuildingsArr;
*/
/********************************************/

void GetInfoDariFile (int *n, int *m, int *nbangunan, TabBuildings *b, MATRIKS *mgraf);

#endif