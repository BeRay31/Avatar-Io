#include <stdio.h>
#include <stdlib.h>
#include "../include1/boolean.h"
#include "../include1/loadinfoawal.h"
#include "../include1/dinamicArr.h"

void GetInfoDariFile (int *n, int *m, int *nbangunan, TabBuildings *b, MATRIKS *mgraf)
{
	/*** KAMUS ***/

	// kamus tinggi dan lebar peta
	int N, M;

	// kamus banyaknya bangunan
	int NBangunan;

	// kamus bangunan
	TabBuildings B; //BuildingsArr B;
	Buildings e;
	char tipe; // tipe bangunan
	int idx, kol; // baris, kolom (posisi)
	int j; // indeks elemen array Bangunan

	// kamus graf
	TabBuildings tg;	//TabGraf tg;
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
			MakeEmpty (&B, NBangunan);//CreateEmptyBangunan(&B, NBangunan);
			MakeEmpty(&tg, (NBangunan*NBangunan)); //CreateEmptyTabGraf(&tg);
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
				B.TI[j] = e;
				j++;
				B.Neff++;
			}
		} else if (countKata > (3*NBangunan+3)){
			Salin(&KataTemp, CKata);
			CharToInt(&elmtGraf, KataTemp);
			// e.armies menyimpan 0 or 1 UNTUK GRAF SEMENTARA
			e.armies = elmtGraf;
			tg.TI[idks] = e;
			//tg.Neff++;
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
			MGraf.Mem[i][j] = tg.TI[k].armies;
			k++;
		}
	}
	(*n) = N;
	(*m) = M;
	(*nbangunan) = NBangunan;
	CopyMATRIKS (MGraf, mgraf);
	CopyTab (B, b);
}