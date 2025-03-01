#include <stdio.h>
#include <stdlib.h>
#include "dinamicArr.h"

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
int NbOfBuildings (TabBuildings Tin, int owner){
    int Nb = 0;
    for(int i=1;i<=Tin.Neff;i++){
        if((Tin).TI[i].owner == owner){
            Nb++;
        }
    }
    return Nb;
}
boolean IsAllLvl4 (TabBuildings Tin, int owner){
    boolean indicator = true;
    for(int i=1;i<=Tin.Neff;i++){
        if((Tin).TI[i].owner == owner && (Tin).TI[i].level != 4){
            indicator = false;
        }
    }
    return indicator;
}
