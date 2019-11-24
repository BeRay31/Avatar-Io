#include <stdio.h>
#include <stdlib.h>
#include "../include1/loadinfoawal.h"
#include "../include1/load.h"

void load (int *n, int *m, int *nbangunan, TabBuildings *b , Queue *q1, Queue *q2, int *turn)
{
	/* KAMUS */
	int CountKata = 0;
	int CountAtribut = 0;
	Kata KataTemp;
	unsigned short int NShortTemp;
	int NTemp;
	// peta
	int N, M;
	// buildings
	int NBangunan;
	int j; // indeks bangunan
	char tipe;
	TabBuildings B;
	Buildings e;
	// graf
	TabBuildings tg;
	int elmtGraf;
	int idks;
	MATRIKS MGraf;
	int k;
	// queue
	int nq1, nq2;
	//Queue Q1, Q2;
	int q1start, q2start;
	int elmtQ;
	// turn
	int Turn;
	/* ALGORITMA */
	STARTKATALOAD();
	while (!EndKata){
		CountKata++;
		if (CountKata == 1) {
			Salin(&KataTemp, CKata);
			CharToInt(&N, KataTemp);
		} else if (CountKata == 2) {
			Salin(&KataTemp, CKata);
			CharToInt(&M, KataTemp);
		} else if (CountKata == 3) {
			Salin(&KataTemp, CKata);
			CharToInt(&NBangunan, KataTemp);
			MakeEmpty (&B, NBangunan);//CreateEmptyBangunan(&B, NBangunan);
			MakeEmpty(&tg, NBangunan*NBangunan); //CreateEmptyTabGraf(&tg);
			CountAtribut = 1;
			j = IdxMin;
			idks = IdxMin;
		} else if ((CountKata > 3) && (CountKata <= (3+(NBangunan*11)))){
			if (CountAtribut == 1) {
				Salin(&KataTemp, CKata);
				CharToUnShortInt(&NShortTemp, KataTemp);
				e.owner = NShortTemp;
				CountAtribut++;
			} else if (CountAtribut == 2) {
				Salin(&KataTemp, CKata);
				CharToInt(&NTemp, KataTemp);
				e.armies = NTemp;
				CountAtribut++;
			} else if (CountAtribut == 3) {
				Salin(&KataTemp, CKata);
				CharToUnShortInt(&NShortTemp, KataTemp);
				e.level = NShortTemp;
				CountAtribut++;
			} else if (CountAtribut == 4){
				Salin(&KataTemp, CKata);
				CharToInt(&NTemp, KataTemp);
				e.incArmy = NTemp;
				CountAtribut++;
			} else if (CountAtribut == 5){
				Salin(&KataTemp, CKata);
				CharToInt(&NTemp, KataTemp);
				e.maxArmyOnBuildings = NTemp;
				CountAtribut++;
			} else if (CountAtribut == 6){
				Salin(&KataTemp, CKata);
				// asumsi defense dari file adalah int
				CharToInt(&NTemp, KataTemp);
				e.defenses = NTemp;
				CountAtribut++;
			} else if (CountAtribut == 7){
				Salin(&KataTemp, CKata);
				CharToInt(&NTemp, KataTemp);
				e.minArmiesToOccupy = NTemp;
				CountAtribut++;
			} else if (CountAtribut == 8) {
				GetTipeBangunan(&tipe, CKata);
				e.buildingsType = tipe;
				CountAtribut++;
			} else if (CountAtribut == 9){
				Salin(&KataTemp, CKata);
				CharToInt(&NTemp, KataTemp);
				e.buildingsIndex = NTemp;
				CountAtribut++;
			} else if (CountAtribut == 10){
				Salin(&KataTemp, CKata);
				CharToInt(&NTemp, KataTemp);
				e.position.X = NTemp;
				CountAtribut++;
			} else if (CountAtribut == 11) {
				Salin(&KataTemp, CKata);
				CharToInt(&NTemp, KataTemp);
				e.position.Y = NTemp;
				CountAtribut = 1;
				B.TI[j] = e;
				j++;
				B.Neff++;
				q1start = 3+(NBangunan*11)+1;
			}
		} else if (CountKata == q1start) {
			// menyimpan nbelmt queue pemain satu
			Salin(&KataTemp, CKata);
			CharToInt(&nq1, KataTemp);
			CreateEmptyQ(q1, nq1);
			//printf("%d ", nq1);
		} else if (CountKata > q1start && CountKata <= q1start+nq1) {
			Salin(&KataTemp, CKata);
			CharToInt(&elmtQ, KataTemp);
			AddQ(q1, elmtQ);
			q2start = q1start+nq1+1;
		} else if (CountKata == q2start){
			// mengambil nbelmt queue pemain kedua
			Salin(&KataTemp, CKata);
			CharToInt(&nq2, KataTemp);
			CreateEmptyQ(q2, nq2);
		} else if (CountKata > q2start && CountKata <= q2start+nq2) {
			Salin(&KataTemp, CKata);
			CharToInt(&elmtQ, KataTemp);
			AddQ(q2, elmtQ);
		} else if (CountKata > q2start+nq2) {
			Salin(&KataTemp, CKata);
			CharToInt(&Turn, KataTemp);
			if(Turn ==1)
			{
				(*turn) = 1;
			}
			else if(Turn ==2)
			{
				(*turn) = 2;
			}
		}
		ADVKATA();
	}
	/*
	MakeMATRIKS(NBangunan, NBangunan, &MGraf);
	k = 1;
	for (int i=1; i<=NBangunan; i++){
		for (int j=1; j<=NBangunan; j++){
			MGraf.Mem[i][j] = tg.TI[k].armies;
			k++;
		}
	}
	*/
	(*n) = N;
	(*m) = M;
	(*nbangunan) = NBangunan;
	CopyTab(B, b);
	//CopyMATRIKS(MGraf, mgraf);
	//Dealokasi(&tg);
}