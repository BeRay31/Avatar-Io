/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
*


//For Windows
//#include <windows.h>
#include <stdio.h>
#include "../include1/pcolor.h"

HANDLE hConsole;
int k;

void print_red(char c) {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, RED);
    printf("%c",c);
    SetConsoleTextAttribute(hConsole, NORMAL);
}

void print_green(char c) {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, GREEN);
    printf("%c",c);
    SetConsoleTextAttribute(hConsole, NORMAL);
}

void print_yellow(char c) {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, YELLOW);
    printf("%c",c);
    SetConsoleTextAttribute(hConsole, NORMAL);
}

void print_blue(char c) {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BLUE);
    printf("%c",c);
    SetConsoleTextAttribute(hConsole, NORMAL);
}

void print_magenta(char c) {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, MAGENTA);
    printf("%c",c);
    SetConsoleTextAttribute(hConsole, NORMAL);
}

void print_cyan(char c) {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("%c",c);
    SetConsoleTextAttribute(hConsole, NORMAL);
}
*/

#include <stdio.h>
#include "../include1/pcolor.h"

void print_red(char c) {
    printf("%s%c", RED, c);
    printf("%s", NORMAL);
}

void print_green(char c) {
    printf("%s%c", GREEN, c);
    printf("%s", NORMAL);
}

void print_yellow(char c) {
    printf("%s%c", YELLOW, c);
    printf("%s", NORMAL);
}

void print_blue(char c) {
    printf("%s%c", BLUE, c);
    printf("%s", NORMAL);
}

void print_magenta(char c) {
    printf("%s%c", MAGENTA, c);
    printf("%s", NORMAL);
}

void print_cyan(char c) {
    printf("%s%c", MAGENTA, c);
    printf("%s", NORMAL);
}
