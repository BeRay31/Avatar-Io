#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkata.h"

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
} ElType;

typedef struct {
  ElType *T;
  int MaxEl; 
} Bangunan;
/********************************************/

/* KONSTRUKTOR ARRAY PENYIMPAN ELEMEN GRAF */
typedef struct { 
  int TI[IdxMax+1];
  int Neff;
} TabGraf;
/*******************************************/

/* ********** SELEKTOR ********** */
#define Elmt(B,i)	   (B).T[(i)]
#define Maxel(B)       (B).MaxEl
#define Building(e)    (e).building
#define Indeks(e)      (e).indeks
#define Kolom(e)       (e).kolom
/* ****************************** */

/******** BANGUNAN *********/
void CreateEmptyBangunan (Bangunan *b, int MaksEl)
{
	(*b).T = (ElType*) malloc ((MaksEl+1) * sizeof(ElType));
	if ((*b).T != NULL){
		Maxel(*b) = MaksEl;
	} else {
		Maxel(*b) = 0;	
	}
}
void TulisIsiBangunan (Bangunan b)
{
	for (int i=1; i<=b.MaxEl; i++){
		printf("%c", b.T[i].building);
		printf(" %d", b.T[i].indeks);
		printf(" %d\n", b.T[i].kolom);
	}
}
void DealokasiBangunan (Bangunan *b)
{
	Maxel(*b) = 0;
	free((*b).T);
}
boolean IsTipeBangunan (Kata src)
{
	int i = src.Length;
	return (src.TabKata[i] == 'C' || src.TabKata[i] == 'T' || src.TabKata[i] == 'F' || src.TabKata[i] == 'V');
}
void GetTipeBangunan (char *tipe, Kata src)
{
	*tipe = src.TabKata[src.Length];
}
/*************************************/

/********* GRAF *********/
void CreateEmptyTabGraf (TabGraf *tg)
{
	(*tg).Neff = 0;
}

void TulisIsiTabGraf (TabGraf tg, int NBangunan)
{
	for (int i=IdxMin; i<=tg.Neff; i++){
		if (i%NBangunan==0){
			printf("%d\n", tg.TI[i]);
		} else {
			printf("%d ", tg.TI[i]);
		}
	}
}
/************************/

/*** FUNGSI LAIN ***/
void CharToInt(int *res, Kata src)
{
	int num = 0;
	for (int i=1; i<=src.Length; i++){
		num = ((num*10) + (src.TabKata[i]-'0'));
	}
	*res = num;
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
void Tulis(Kata kata)
{
	for (int i=1; i<=kata.Length; i++){
		printf("%c", kata.TabKata[i]);
	}
	printf("\n");
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

void TampilkanKata (Kata kata)
{
	for (int i=1; i<=kata.Length; i++){
		printf("%c", kata.TabKata[i]);
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
    printf("Masukan string: ");
    fgets(str, sizeof(str), stdin);
    int n = PanjangString(str);
    for (int i=0; i<n; i++){
    	(*kata).TabKata[i+1] = str[i];
    }
    (*kata).Length = n;
}
/** test ***/
int main(){
	/*** KAMUS ***/
	// kamus tinggi dan lebar peta
	int N, M;
	// kamus banyaknya bangunan
	int NBangunan;
	// kamus bangunan
	Bangunan B;
	ElType e;
	char tipe; // tipe bangunan
	int idx, kol; // baris, kolom
	int j; // indeks elemen array Bangunan
	// kamus graf
	TabGraf tg;
	int elmtGraf; // nilai elemen 1 atau 0
	int idks; // indeks elemen array Tabgraf
	// kamus umum
	int countKata; // menghitung kata yg telah dibaca
	int count;
	Kata KataTemp; // menyimpan kata sementara
	
	/*** ALGORITMA ***/
	STARTKATA();
	countKata = 0;
	while (!EndKata) {
		countKata++;
		if (countKata == 1){
			Salin(&KataTemp, CKata);
			CharToInt(&N, KataTemp);
		} else if (countKata == 2) {
			Salin(&KataTemp, CKata);
			CharToInt(&M, KataTemp);
		} else if (countKata == 3){
			Salin(&KataTemp, CKata);
			CharToInt(&NBangunan, KataTemp);
			CreateEmptyBangunan(&B, NBangunan);
			CreateEmptyTabGraf(&tg);
			idks = IdxMin; // indeks pertama array graf
			j = IdxMin; // indeks pertama bangunan
			count = 1;
		} else if ((countKata > 3) && (countKata <= (3*NBangunan+3))){
			if (count == 1){// && (IsTipeBangunan(CKata))){
				count = 2; // = 2
				GetTipeBangunan(&tipe, CKata);
				e.building = tipe;
			} else if (count == 2) {
				count = 3; // = 3;
				Salin(&KataTemp, CKata);
				CharToInt(&idx, KataTemp);
				e.indeks = idx;
			} else if (count == 3){
				count = 1;
				Salin(&KataTemp, CKata);
				CharToInt(&kol, KataTemp);
				e.kolom = kol;
				B.T[j] = e;
				j++;
			}
		} else if (countKata > (3*NBangunan+3)){
			Salin(&KataTemp, CKata);
			CharToInt(&elmtGraf, KataTemp);
			tg.TI[idks] = elmtGraf;
			tg.Neff++;
			idks++;
		}
		ADVKATA();
	}
	printf("tinggi peta %d\n",N);
	printf("lebar peta %d\n",M);
	printf("banyaknya bangunan %d\n",NBangunan);
	printf("info bangunan <tipe bangunan, baris, kolom>\n");
	TulisIsiBangunan(B);
	printf("info graf\n");
	TulisIsiTabGraf(tg, NBangunan);
	// kamus command
	Kata ATTACK, LEVEL_UP, SKILL, UNDO, END_TURN, SAVE;
	// ATTTACK
	ATTACK.TabKata[1] = 'A';
	ATTACK.TabKata[2] = 'T';
	ATTACK.TabKata[3] = 'T';
	ATTACK.TabKata[4] = 'A';
	ATTACK.TabKata[5] = 'C';
	ATTACK.TabKata[6] = 'K';
	ATTACK.Length = 6;
	// LEVEL_UP
	LEVEL_UP.TabKata[1] = 'L';
	LEVEL_UP.TabKata[2] = 'E';
	LEVEL_UP.TabKata[3] = 'V';
	LEVEL_UP.TabKata[4] = 'E';
	LEVEL_UP.TabKata[5] = 'L';
	LEVEL_UP.TabKata[6] = '_';
	LEVEL_UP.TabKata[7] = 'U';
	LEVEL_UP.TabKata[8] = 'P';
	LEVEL_UP.Length = 8;
	// SKILL
	SKILL.TabKata[1] = 'S';
	SKILL.TabKata[2] = 'K';
	SKILL.TabKata[3] = 'I';
	SKILL.TabKata[4] = 'L';
	SKILL.TabKata[5] = 'L';
	SKILL.Length = 5;
	// UNDO
	UNDO.TabKata[1] = 'U';
	UNDO.TabKata[2] = 'N';
	UNDO.TabKata[3] = 'D';
	UNDO.TabKata[4] = 'O';
	UNDO.Length = 4;
	// END_TURN
	END_TURN.TabKata[1] = 'E';
	END_TURN.TabKata[2] = 'N';
	END_TURN.TabKata[3] = 'D';
	END_TURN.TabKata[4] = '_';
	END_TURN.TabKata[5] = 'T';
	END_TURN.TabKata[6] = 'U';
	END_TURN.TabKata[7] = 'R';
	END_TURN.TabKata[8] = 'N';
	END_TURN.Length = 8;
	// SAVE
	SAVE.TabKata[1] = 'S';
	SAVE.TabKata[2] = 'A';
	SAVE.TabKata[3] = 'V';
	SAVE.TabKata[4] = 'E';
	SAVE.Length = 4; 
	
	// kamus coba
	Kata serang;
	InputString(&serang);
	TampilkanKata(serang);
	return 0;
}