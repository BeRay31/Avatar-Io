//Load File info
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
   F.S. : CC ≠ BLANK atau CC = ENTER */
{
	/* KAMUS LOKAL */
	/* ALGORITMA */
	while (CC == BLANK || CC != ENTER) {
		ADV();
	}
}
void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = ENTER;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	/* KAMUS LOKAL */
	/* ALGORITMA */
	START();
	IgnoreBlank();
	if (CC == ENTER){
		EndKata = true;
	} else {
		EndKata = false;
		SalinKata();
	}
}

void STARTCOMMAND()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = EOF;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	/* KAMUS LOKAL */
	/* ALGORITMA */
	printf("ENTER COMMAND : ");
	STARTSTDIN();
	IgnoreBlank();
	if (CC == EOF || CC == ENTER){
		EndKata = true;
	} else {
		EndKata = false;
		SalinKata();
	}
}

void Command (Kata *kata)
/* F.S. : nilai command */
{
	STARTCOMMAND();
	while (!EndKata) {
		Salin(kata, CKata);
		TulisKata(*kata); // buat ngecek
		ADVKATA();
	}
}
	
void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika CC = ENTER, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	/* KAMUS LOKAL */
	/* ALGORITMA */
	IgnoreBlank();
	if (CC == ENTER){
		EndKata = true;
	} else {
		SalinKata();
		IgnoreBlank();
	}
}
void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = ENTER;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	/* KAMUS LOKAL */
	int i;
	/* ALGORITMA */
	i = 1;
	while (CC != ENTER && CC != BLANK) {
		CKata.TabKata[i] = CC;
		ADV();
		if (CC == ENTER || CC == BLANK || i == NMax || CC == EOF){
			break;
		} else {
			i++;
		}
	}
	/*
	if (i==NMax) {
		while (CC != BLANK && CC != ENTER) {
			ADV();
		}
	}
	*/
	CKata.Length = i;
}

void Salin(Kata* dest, Kata src)
/* Menyalin kata
   I.S. : dest sembarang, src sebuah kata yang valid
   F.S. : dest merupakan kata dengan panjang yang sama dengan src
          dan tiap karakter dest sama dengan src */
{
	(*dest).Length = src.Length;
	for (int i=1; i<=src.Length; i++){
		(*dest).TabKata[i] = src.TabKata[i];
	}
}

/* FUNGSI LAIN */
boolean IsKataSama (Kata k1, Kata k2)
{
	int i = 1;
	boolean sama = true;
	if (k1.Length == k2.Length) {
		while (true) {
			if (k1.TabKata[i] != k2.TabKata[i]) {
				sama = false;
				break;
			} else {
				i++;
			}
		}
	} else {
		sama = false;
	}
	return sama;
}

void TulisKata (Kata kata)
/* F.S : Menulis kata diakhiri dengan enter */
{
	for (int i=1; i<=kata.Length; i++) {
		if (i != kata.Length) {
			printf("%c\n", kata.TabKata[i]);
		} else {
			printf("%c", kata.TabKata[i]);
		}
	}
}

void CharToInt(int *res, Kata src)
{
	int num = 0;
	for (int i=1; i<=src.Length; i++){
		num = ((num*10) + (src.TabKata[i]-'0'));
	}
	*res = num;
}

void CharToUnShortInt(unsigned short int *res, Kata src)
{
	unsigned short int num = 0;
	for (int i=1; i<=src.Length; i++){
		num = ((num*10) + (src.TabKata[i]-'0'));
	}
	*res = num;
}

int BoolToInt (boolean True)
{
	if (True){
		return 1;
	} else {
		return 0;
	}
}

void GetTipeBangunan (char *tipe, Kata src)
{
	*tipe = src.TabKata[src.Length];
}