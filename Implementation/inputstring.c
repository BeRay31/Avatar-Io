#include <stdio.h>
#include "../include1/mesinkata.h"

void InputString2 (Kata *kata)
{
    char str;
    int i;

    scanf("%c", &str);

    if (str != '\n') {
        i = 1;
        (*kata).TabKata[i] = str;
        while (str != '\n') {
            scanf("%c", &str);
            i++;
            (*kata).TabKata[i] = str;
        }
        (*kata).Length = i;
    }
}

    

    printf("ENTER COMMAND: ");
    fgets(str, sizeof(str), stdin);
    int n = PanjangString(str);
    for (int i=0; i<n; i++){
        (*kata).TabKata[i+1] = str[i];
    }
    (*kata).Length = n;
}

int main () {
    Kata kata;

    InputString(&kata);
    // panjang kata
    for (int i=1; i<100; )
}