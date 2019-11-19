#include <stdio.h>
#include "../include1/dinamicArr.h"
#include <stdlib.h>

//to store BUilding

void MakeEmpty(TabBuildings *T, int maxel)
{
    (*T).MaxEl = maxel;
    (*T).TI = (ArrType *) malloc (((*T).MaxEl+1)*sizeof(ArrType));
    (*T).Neff = 0;

/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
}
void Dealokasi(TabBuildings *T)
{
    free(T);

/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
}

void TulisTabBuilding (TabBuildings T)
{

    for(int i = 1; i<=(T).Neff;i++)
    {
        printf("%d. %c %d %d \n",i,T.TI[i].buildingsType,T.TI[i].position.X,T.TI[i].position.Y);
    }
}
/*
{I.S Tab Defined}
{F.S Tab Printed}
*/

void CopyTab(TabBuildings Tin, TabBuildings *Tout)
{
    MakeEmpty(Tout,Tin.Neff);
    for (int i = 1;i<=Tin.Neff;i++)
    {
        (*Tout).TI[i] = Tin.TI[i];
    }
    (*Tout).Neff = Tin.Neff;
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */    
}

