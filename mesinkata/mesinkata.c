//Load File info
#include <stdio.h>
#include "../Booelan/boolean.h"
#include "../mesinkar/mesinkar.h"
#include "mesinkata.h"

#define NMax 50
#define BLANK ' '
#define ENTER '\n'

/* State Mesin Kata */
boolean EndKata;
boolean EndCommand;
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

void STARTKATALOAD()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = EOF;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	/* KAMUS LOKAL */
	/* ALGORITMA */
	STARTLOAD();
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

/* FUNGSI LAIN */
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

boolean IsKataSama (Kata k1, Kata k2)
{
	if (k1.Length == k2.Length) {
		for (int i=1; i<=k1.Length; i++){
			if (k1.TabKata[i] != k2.TabKata[i]) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}

void GetTipeBangunan (char *tipe, Kata src)
{
	*tipe = src.TabKata[src.Length];
}

/* untuk command */
void STARTCOMMAND()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = EOF;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	/* KAMUS LOKAL */
	/* ALGORITMA */
	STARTSTDIN();
	IgnoreBlankStdin();
	if (CC == '\n'){
		EndCommand = true;
	} else {
		EndCommand = false;
		SalinCOMMAND();
	}
}

void ADVCOMMAND()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin EOF
          Jika CC = EOF, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	/* KAMUS LOKAL */
	/* ALGORITMA */
	IgnoreBlankStdin();
	if (CC == '\n'){
		EndCommand = true;
	} else {
		SalinCOMMAND();
		//IgnoreBlank();
	}
}

void SalinCOMMAND()
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
		ADVSTDIN();
		if (CC == '\n') {
			break;
		} else {
			i++;
		}
	}
	CKata.Length = i;
}

void input (Kata *kata) 
/* input dengan hasil kata */
{
	STARTCOMMAND();
	while (!EndCommand) {
		Salin(kata, CKata);
		ADVCOMMAND();
	}
}

void inputf (int *num) {
	/* KAMUS LOKAL */
	Kata inp;
	int temp;
	/* ALGORITMA */
	input(&inp);
	CharToInt(&temp, inp);
	(*num) = temp;
}

void Command (Kata *kata)
/* command dalam game */
{
	printf("ENTER COMMAND : ");
	input(kata);
}

void IgnoreBlankStdin()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = EOF */
{
	/* KAMUS LOKAL */
	/* ALGORITMA */
	while (CC == BLANK) {
		ADVSTDIN();
	}
}
