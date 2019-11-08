#include <stdio.h>
#include "../include1/dinamicArr.h"
#include <stdlib.h>

//to store BUilding

void MakeEmpty(TabBuildings *T, int maxel)
{
    MaxEl(*T) = maxel;
    TI(*T) = (int *) malloc ((MaxEl(*T)+1)*sizeof(int));
    Neff(*T) = 0;

/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
}
void Dealokasi(TabBuildings *T)
{
    free(T);

/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
}
int NbElmt(TabBuildings T)
{
    return (Neff(T));
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */    
}
int MaxElement(TabBuildings T)
{
    return (MaxEl(T)-IdxMin+1);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
}
IdxType GetFirstIdx(TabBuildings T)
{
    if (Neff(T)!=0)
    {
        return IdxMin;
    }
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */    
}
IdxType GetLastIdx(TabBuildings T)
{
    if (Neff(T)!=0)
    {
        return (Neff(T));
    }
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */    
}
boolean IsIdxValid(TabBuildings T, IdxType i)
{
    return (i>=1 && i<=MaxEl(T));
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
}
boolean IsIdxEff(TabBuildings T, IdxType i)
{
    return (i>=GetFirstIdx(T)&&i<=GetLastIdx(T));
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */    
}
boolean IsEmpty(TabBuildings T)
{
    return (Neff(T)==0);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
}
boolean IsFull(TabBuildings T)
{
    return (Neff(T)==MaxEl(T));
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
}
void TulisIsiTab(TabBuildings T)
{      
    int i;
    if(!(IsEmpty(T)))
    {
        printf("[");
        for( i=1;i<Neff(T);i++)
        {
            printf("%d,",Elmt(T,i));
        }
            printf("%d]",Elmt(T,Neff(T)));
    }
    else
    {
        printf("[]");
    }
}

void CopyTab(TabBuildings Tin, TabBuildings *Tout)
{
    MakeEmpty(&*Tout,Neff(Tin));
    Neff(*Tout) = Neff(Tin);
    for (int i=1;i<=Neff(Tin);i++)
    {
        Elmt(*Tout,i)=Elmt(Tin,i);
    }
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */    
}

