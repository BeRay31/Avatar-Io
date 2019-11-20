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

int PanjangString (char str[]) {
    int c = 0;
    while (str[c] != '\0'){
        c++;
    }
    return (c-1);
}

void InputString (Kata *kata)
{
    char str[100];
    printf("ENTER COMMAND: ");
    fgets(str, sizeof(str), stdin);
    int n = PanjangString(str);
    for (int i=0; i<n; i++){
    	(*kata).TabKata[i+1] = str[i];
    }
    (*kata).Length = n;
}

void GetTipeBangunan (char *tipe, Kata src)
{
	*tipe = src.TabKata[src.Length];
}