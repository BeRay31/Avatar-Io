#include <stdio.h>
#include "../include1/boolean.h"
#include "../include1/mesinkar.h"

int main()
{
    /*
    gcc -o test-mesinkar driver-mesinkar.c mesinkar.c
    */
   START();
   while (CC != EOF) {
       printf(" %c", CC);
       ADV();
   }
   printf("\n");
   STARTSTDIN();
   ADVSTDIN();
}