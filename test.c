#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "infofileeksternal.h"

int main(){
	/*** KAMUS ***/
	int n, m, nbangunan;
	Bangunan b;
	MATRIKS mgraf;
	/*** test ***/
	GetInfoDariFile (&n, &m, &nbangunan, &b, &mgraf);
	printf("tinggi peta %d\n",n);
	printf("lebar peta %d\n",m);
	printf("banyaknya bangunan %d\n",nbangunan);
	printf("info bangunan <tipe bangunan, baris, kolom>\n");
	TulisIsiBangunan(b);
	printf("info graf\n");
	TulisMATRIKS(mgraf);
	return 0;
}