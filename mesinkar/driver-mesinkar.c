#include <stdio.h>
#include "Booelan/boolean.h"
#include "../mesinkata/mesinkata.h"

int main()
{
    /*
    gcc -o test-mesinkar driver-mesinkar.c mesinkar.c
    */
   Kata TempKata;
   STARTKATA();
   while (!EndKata) {
       Salin(&TempKata, CKata);
       for (int i=1; i<=TempKata.Length; i++){
           if (i==TempKata.Length) {
               printf("%c\n", TempKata.TabKata[i]);
           } else {
               printf("%c", TempKata.TabKata[i]);
           }
       }
       ADVKATA();
   }

   STARTKATALOAD();
   while (!EndKata) {
       Salin(&TempKata, CKata);
       for (int i=1; i<=TempKata.Length; i++){
           if (i==TempKata.Length) {
               printf("%c\n", TempKata.TabKata[i]);
           } else {
               printf("%c", TempKata.TabKata[i]);
           }
       }
       ADVKATA();
   }

   STARTCOMMAND();
   while (!EndKata) {
       Salin(&TempKata, CKata);
       for (int i=1; i<=TempKata.Length; i++){
           if (i==TempKata.Length) {
               printf("%c\n", TempKata.TabKata[i]);
           } else {
               printf("%c", TempKata.TabKata[i]);
           }
       }
       ADVCOMMAND();
   }


}