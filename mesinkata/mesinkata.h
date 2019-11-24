/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../Booelan/boolean.h"
#include "../mesinkar/mesinkar.h"

#define NMax 50
#define BLANK ' '
#define ENTER '\n'

/* ********** KONSTRUKTOR ********** */
typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* ****************************** */

/* State Mesin Kata */
extern boolean EndKata;
extern boolean EndCommand;
extern Kata CKata;
void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = EOF */

void STARTKATA();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = EOF;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void STARTKATALOAD();

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin EOF
          Jika CC = EOF, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = EOF;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

/* COMMAND */
void STARTCOMMAND();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVCOMMAND();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinCOMMAND();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void input (Kata *kata); 
/* input dengan hasil kata */

void inputf (int *num);
/* input dengan hasil int */

void Command (Kata *kata);
/* command dalam game */


void IgnoreBlankStdin();

/* FUNGSI LAIN */
void CharToInt(int *res, Kata src);

void CharToUnShortInt(unsigned short int *res, Kata src);

int BoolToInt (boolean True);

void Salin(Kata* dest, Kata src);
/* Menyalin kata
   I.S. : dest sembarang, src sebuah kata yang valid
   F.S. : dest merupakan kata dengan panjang yang sama dengan src
          dan tiap karakter dest sama dengan src */


boolean IsKataSama (Kata k1, Kata k2);

int PanjangString (char str[]);

void GetTipeBangunan (char *tipe, Kata src);

void InputString (Kata *kata);

/* untuk command */
void STARTCOMMAND();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = EOF;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVCOMMAND();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin EOF
          Jika CC = EOF, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinCOMMAND();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = EOF;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void input (Kata *kata); 
/* input dengan hasil kata */


void inputf (int *num);

void Command (Kata *kata);
/* command dalam game */

void IgnoreBlankStdin();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = EOF */
#endif
