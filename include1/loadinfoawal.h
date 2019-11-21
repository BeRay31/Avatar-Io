#ifndef LOADINFOAWAL_H
#define LOADINFOAWAL_H

#include "boolean.h"
#include "dinamicArr.h"
#include "mesinkata.h"
#include "matriks.h"
#include "Buildings.h"


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