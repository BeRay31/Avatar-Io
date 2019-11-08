#ifndef LOADINFOAWAL_H
#define LOADINFOAWAL_H

#include "boolean.h"
#include "mesinkata.h"
#include "matriks.h"
#include "Buildings.h"

/*  Kamus Umum */
#define IdxMax 10000
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */

/* KONSTRUKTOR ARRAY PENYIMPAN INFO BANGUNAN */
typedef struct {
  Buildings *T;
  int MaxElmt; 
} BuildingsArr;
/********************************************/

/* KONSTRUKTOR ARRAY PENYIMPAN ELEMEN GRAF */
typedef struct { 
  int TI[IdxMax+1];
  int Neff;
} TabGraf;
/*******************************************/
/******** BANGUNAN ******/
void CreateEmptyBangunan (BuildingsArr *b, int MaksEl); //create array of Buildings with maxElmt Maksel
void TulisIsiBangunan (BuildingsArr b); //write Array of building 
void CopyBangunan (BuildingsArr bin, BuildingsArr *bout); //copy array of Building
void DealokasiBangunan (BuildingsArr *b); //free array of building
boolean IsTipeBangunan (Kata src);
void GetTipeBangunan (char *tipe, Kata src);
/************************/
/********* GRAF *********/
void CreateEmptyTabGraf (TabGraf *tg);
void TulisIsiTabGraf (TabGraf tg, int NBangunan);
/************************/
/*** FUNGSI LAIN ***/
void CharToInt(int *res, Kata src);
void CharToUnShortInt(int *res, Kata src);
int BoolToInt (boolean True);
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
void GetInfoDariFile (int *n, int *m, int *nbangunan, BuildingsArr *b, MATRIKS *mgraf);

#endif