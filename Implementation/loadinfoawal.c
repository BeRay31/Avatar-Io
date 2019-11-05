#include <stdio.h>
#include <stdlib.h>
#include "../include1/boolean.h"
#include "../include1/loadinfoawal.h"

#define IdxMax 10000
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */

/******** BANGUNAN *********/
void CreateEmptyBangunan (BuildingsArr *b, int MaksEl)
{
	(*b).T = (Buildings*) malloc ((MaksEl+1) * sizeof(Buildings));
	if ((*b).T != NULL){
		(*b).MaxEl = MaksEl;
	} else {
		(*b).MaxEl = 0;	
	}
}
void TulisIsiBangunan (BuildingsArr b)
{
	for (int i=1; i<=b.MaxEl; i++){
		printf("%d.", b.T[i].buildingsIndex);
		printf(" %c", b.T[i].buildingsType);
		printf(" (%d,%d)\n", b.T[i].position.X,b.T[i].position.Y);
	}
}
void CopyBangunan (BuildingsArr bin, BuildingsArr *bout)
{
	CreateEmptyBangunan (bout, bin.MaxEl);
	for (int i=1; i<=bin.MaxEl; i++){
		(*bout).T[i].buildingsType = bin.T[i].buildingsType;
		(*bout).T[i].buildingsIndex = bin.T[i].buildingsIndex;
		(*bout).T[i].position = bin.T[i].position;
	}
}
void DealokasiBangunan (BuildingsArr *b)
{
	(*b).MaxEl = 0;
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
    printf("ENTER COMMAND: ");
    fgets(str, sizeof(str), stdin);
    int n = PanjangString(str);
    for (int i=0; i<n; i++){
    	(*kata).TabKata[i+1] = str[i];
    }
    (*kata).Length = n;
}

void GetInfoDariFile (int *n, int *m, int *nbangunan, BuildingsArr *b, MATRIKS *mgraf)
{
	/*** KAMUS ***/

	// kamus tinggi dan lebar peta
	int N, M;

	// kamus banyaknya bangunan
	int NBangunan;

	// kamus bangunan
	BuildingsArr B;
	Buildings e;
	char tipe; // tipe bangunan
	int idx, kol; // baris, kolom (posisi)
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
				e.buildingsType = tipe;
			} else if (count == 2) {
				count = 3; // = 3;
				Salin(&KataTemp, CKata);
				CharToInt(&idx, KataTemp);
				e.position.X = idx;
			} else if (count == 3){
				count = 1;
				Salin(&KataTemp, CKata);
				CharToInt(&kol, KataTemp);
				e.position.Y = kol;
				e.buildingsIndex = j;
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
	// MATRIKS GRAF
	// kamus
	MATRIKS MGraf;
	int k;
	MakeMATRIKS(NBangunan, NBangunan, &MGraf);
	// isi matriks
	k = 1; // indeks array graf
	for (int i=1; i<=NBangunan; i++){
		for (int j=1; j<=NBangunan; j++){
			MGraf.Mem[i][j] = tg.TI[k];
			k++;
		}
	}
	(*n) = N;
	(*m) = M;
	(*nbangunan) = NBangunan;
	CopyMATRIKS (MGraf, mgraf);
	CopyBangunan (B, b);
}