#include <stdio.h>
#include "../../include1/boolean.h"
#include "../../include1/mesinkata.h"

int main()
{
    /*
    gcc -o test-mesinkata driver-mesinkata.c mesinkar.c mesinkata.c
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