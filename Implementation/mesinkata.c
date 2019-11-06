/* NIM/NAMA		: 13518004/QURRATA A'YUNI   */
/* HARI/TANGGAL : MINGGU, 29 SEPTEMBER 2019 */
/* File: mesinkata.C */
/* Definisi Mesin Kata: Model Akuisisi Versi I */
#include <stdio.h>
#include "../include1/boolean.h"
#include "../include1/mesinkar.h"
#include "../include1/mesinkata.h"

#define NMax 50
#define BLANK ' '
#define ENTER '\n'

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = EOF */
{
	/* KAMUS LOKAL */
	/* ALGORITMA */
	while (CC == BLANK || CC == ENTER) {
		ADV();
	}
}
void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = EOF;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	/* KAMUS LOKAL */
	/* ALGORITMA */
	START();
	IgnoreBlank();
	if (CC == EOF){
		EndKata = true;
	} else {
		EndKata = false;
		SalinKata();
	}
}
	
void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin EOF
          Jika CC = EOF, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	/* KAMUS LOKAL */
	/* ALGORITMA */
	IgnoreBlank();
	if (CC == EOF){
		EndKata = true;
	} else {
		SalinKata();
		//IgnoreBlank();
	}
}
void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = EOF;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	/* KAMUS LOKAL */
	int i;
	/* ALGORITMA */
	i = 1;
	for(;;) {
		CKata.TabKata[i] = CC;
		ADV();
		if ((CC == EOF) || (CC == BLANK) || CC == ENTER) {
			break;
		} else {
			i++;
		}
	}
	CKata.Length = i;
}
