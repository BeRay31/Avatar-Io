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

void TulisIsiTab(TabBuildings T)
{      
    int i;
    if(!(IsEmpty(T)))
    {
        printf("[");
        for( i=1;i<T.Neff;i++)
        {
            printf("%d,",T.TI[i]);
        }
            printf("%d]",T.TI[T.Neff]);
    }
    else
    {
        printf("[]");
    }
}

void CopyTab(TabBuildings Tin, TabBuildings *Tout)
{
    MakeEmpty(&*Tout,(Tin).Neff);
    (*Tout).Neff = (Tin).Neff;
    for (int i=1;i<=(Tin).Neff;i++)
    {
        (*Tout).TI[i] = Tin.TI[i];
    }
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */    
}

