#ifndef INFOFILEEKSTERNAL_H
#define INFOFILEEKSTERNAL_H

#include "boolean.h"
#include "mesinkata.h"
#include "matriks.h"

/*  Kamus Umum */
#define IdxMax 10000
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */

/* KONSTRUKTOR ARRAY PENYIMPAN INFO BANGUNAN */
typedef struct {
  char building;
  int indeks;
  int kolom;
} InfoBangunan;

typedef struct {
  InfoBangunan *T;
  int MaxEl; 
} Bangunan;
/********************************************/

/* KONSTRUKTOR ARRAY PENYIMPAN ELEMEN GRAF */
typedef struct { 
  int TI[IdxMax+1];
  int Neff;
} TabGraf;
/*******************************************/
/******** BANGUNAN ******/
void CreateEmptyBangunan (Bangunan *b, int MaksEl);
void TulisIsiBangunan (Bangunan b);
void CopyBangunan (Bangunan bin, Bangunan *bout);
void DealokasiBangunan (Bangunan *b);
boolean IsTipeBangunan (Kata src);
void GetTipeBangunan (char *tipe, Kata src);
/************************/
/********* GRAF *********/
void CreateEmptyTabGraf (TabGraf *tg);
void TulisIsiTabGraf (TabGraf tg, int NBangunan);
/************************/
/*** FUNGSI LAIN ***/
void CharToInt(int *res, Kata src);
void Salin(Kata* dest, Kata src);
/* Menyalin kata
   I.S. : dest sembarang, src sebuah kata yang valid
   F.S. : dest merupakan kata dengan panjang yang sama dengan src
          dan tiap karakter dest sama dengan src */
void Tulis(Kata kata);
boolean IsKataSama (Kata k1, Kata k2);
void TampilkanKata (Kata kata);
int PanjangString (char str[]);
void InputString (Kata *kata);
void GetInfoDariFile (int *n, int *m, int *nbangunan, Bangunan *b, MATRIKS *mgraf);

#endif