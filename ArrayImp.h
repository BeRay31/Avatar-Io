#ifndef __ARRIMPT_H__
#define __ARRIMP_H__
#define IdxMax 1000
#define IdxMin 1
#define IdxUndef -999 
#define ValUndef -999
#include "boolean.h"
typedef int IdxType;
typedef int ElType;   
 
typedef struct { 
  ElType TI[IdxMax+1];
} TabInt;

#define Elmt(T,i) (T).TI[(i)]

void MakeEmpty (TabInt * T);
int NbElmt (TabInt T);
int MaxNbEl (TabInt T);

IdxType GetFirstIdx (TabInt T);
IdxType GetLastIdx (TabInt T);
boolean IsIdxValid (TabInt T, IdxType i);
boolean IsIdxEff (TabInt T, IdxType i);
boolean IsEmpty (TabInt T);
boolean IsFull (TabInt T);
void TulisIsiTab (TabInt T);

boolean IsEQ (TabInt T1, TabInt T2);

IdxType Search1 (TabInt T, ElType X);

boolean SearchB (TabInt T, ElType X);

void MaxMin (TabInt T, ElType * Max, ElType * Min);

ElType SumTab (TabInt T);

int CountX (TabInt T, ElType X);

void Sort (TabInt * T, boolean asc);

void AddAsLastEl (TabInt * T, ElType X);

void DelLastEl (TabInt * T, ElType * X);

#endif