/* File: mesinkar.c */
/* Implementasi Mesin Karakter */
//Load File Info
#include "../include1/mesinkar.h"
#include <stdio.h>
#include <stdlib.h>

char CC;
boolean EOP;

static FILE * pita;

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pita = fopen("konfigurasi.txt","rt");
    //pita = fopen("save.dat","rt");
    ADV();
}

void STARTLOAD() {
    /* Algoritma */
    pita = fopen("save.dat","rt");
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    CC = fgetc(pita);
    if (CC == EOF) {
       fclose(pita);
    }
}

void STARTSTDIN() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    /* pita = fopen("pitakar.txt","r"); */
    pita = stdin;
    ADVSTDIN();
}

void ADVSTDIN() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    CC = fgetc(pita);
    if (CC == '\n') {
        /* do nothing */
    }
}
