#include <stdio.h>
#include "matriks.h"

//Map Representation

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
{
    (*M).NBrsEff = NB;
    (*M).NKolEff = NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
{
    MakeMATRIKS((MIn).NBrsEff,(MIn).NKolEff,MHsl);
    for (int i = 1;i<=(MIn).NBrsEff;i++)
    {
        for (int j = 1;j<=(MIn).NKolEff;j++)
        {
            (*MHsl).Mem[i][j] = (MIn).Mem[i][j];
        }
    }
}
/* Melakukan assignment MHsl  MIn */
void TulisMATRIKS (MATRIKS M)
{
    for (int i = 1;i<=(M).NBrsEff;i++)
    {
        for (int j = 1;j<=(M).NKolEff;j++)
        {
            if(j!=(M).NKolEff)
            {
                printf ("%d ",(M).Mem[i][j]);
            }
            else if(j==(M).NKolEff && i!=(M).NBrsEff)
            {
                printf ("%d\n",(M).Mem[i][j]);
            }
            else if (j==(M).NKolEff && i==(M).NBrsEff)
            {
                printf("%d",(M).Mem[i][j]);
            }
        }
    }
}