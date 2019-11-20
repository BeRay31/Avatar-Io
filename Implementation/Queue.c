#include "../include1/Queue.h"
#include <stdlib.h>
/* 
    Skill List: 
        1. Instant Upgrade
        2. Shield
        3. Extra Turn
        4. Attack Up
        5. Critical Hit
        6. Instant Reinforcement
        7. Barrage
*/
/*
/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q)
{
    return((Q).HEAD==Nil && (Q).TAIL==Nil);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQ (Queue Q)
{
    return (NBElmtQ(Q) == (Q).MaxEl);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQ (Queue Q)
{
    if(IsEmptyQ(Q))
    {
        return 0;
    }
    else if((Q).HEAD>(Q).TAIL)
    {
        return ((Q).MaxEl-(((Q).HEAD-(Q).TAIL-1)));
    }
    else if((Q).TAIL>=(Q).HEAD)
    {
        return ((Q).TAIL - (Q).HEAD + 1);
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q, int Max)
{
    (*Q).T = (int*) malloc ((Max+1) * sizeof(int));
    if((*Q).T!=NULL)
    {
        (*Q).MaxEl = Max;
        (*Q).HEAD = Nil;
        (*Q).TAIL = Nil;
    }
    else//failure to allocate
    {
        (*Q).MaxEl = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiQ(Queue * Q)
{
    (*Q).MaxEl =0;
    free((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, (Q).MaxEl diset 0 */

/* *** Primitif Add/Delete *** */
void AddQ (Queue * Q, int X)
{
    if(IsEmptyQ(*Q))
    {
        (*Q).HEAD = 1;
        (*Q).TAIL += 1;
        (*Q).T[(*Q).TAIL] = X;
    }
    else
    {
        if((*Q).TAIL!=(*Q).MaxEl)
        {
            (*Q).TAIL +=1;
            (*Q).T[(*Q).TAIL] = X;
        }
        else if((*Q).TAIL==(*Q).MaxEl)
        {
            (*Q).TAIL =1;
            (*Q).T[(*Q).TAIL] =X;
        }
    }
}
void InitializeQueue(Queue *Q1, Queue *Q2){
    CreateEmptyQ(&(*Q1),10);
    CreateEmptyQ(&(*Q2),10);
    (*Q1).HEAD = 1;
    (*Q1).TAIL = 1;
    (*Q2).HEAD = 1;
    (*Q2).TAIL = 1;

}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void DelQ (Queue * Q, int * X)
{
    if((*Q).HEAD==(*Q).TAIL)
    {
        (*Q).HEAD = Nil;
        (*Q).TAIL = Nil;
    }
    else
    {
        *X = (*Q).T[(*Q).HEAD];
        if((*Q).HEAD!=(*Q).MaxEl)
        {
            (*Q).HEAD++;
        }
        else
        {
            (*Q).HEAD = 1;
        }
        
    }
    
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */