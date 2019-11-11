// FIle : mesin_kata.c
// Tanggal : 25 September 2019
// Naufal Alim Wahib

#include <stdio.h>
#include "mesin_kata.h"
#include "mesin_kar.h"
#include "boolean.h"
#include <stdlib.h>

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

//{ ***** Primitif-Primitif Mesin Kata ***** }
void Ignore_Blank()
{
    while ((CC == BLANK) && (CC != MARK))
    {
        ADV ();
    }
    
}
/*{ Mengabaikan satu atau beberapa BLANK }
{ I.S. : CC sembarang }
{ F.S. : CC ? BLANK atau CC = MARK }*/
void STARTKATA(char* filename)
{
	START(filename);
    Ignore_Blank();
    if ((CC == MARK) || (CC == BLANK))
    {
        EndKata = true;
    }else
    {
        EndKata = false;
        SalinKata();
    }
    
    
    
}
/*{ I.S. : CC sembarang, filename merupakan string nama file pita kata yang akan dibaca }
{ F.S. : EndKata = true, dan CC = Mark; }
{        atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
         CC karakter pertama sesudah karakter terakhir kata }*/
void ADVKATA()
{
    Ignore_Blank();
    if (CC == MARK)
    {
        EndKata = true;
    } else
    {
        SalinKata();
    }
}
/*{ I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
         dari kata yg sudah diakuisisi }
{ F.S. : Jika CC = MARK, maka EndKata = true
         atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
         CC karakter pertama sesudah karakter terakhir kata }*/
void SalinKata()
{
    int i = 1; /* inisialisasi */
/* Algoritma*/
    for (;;) {
        CKata.TabKata[i] == CC;
        ADV();
        if ((CC == MARK) || (CC == BLANK))
        {
            
            break;
        }else
        {
            i++;
        }       
    }
    CKata.Length = i;
}
/*{ Mengakuisisi kata, menyimpan dalam CKata }
{ I.S. : CC adalah karakter pertama dari kata }
{ F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
         NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
         karakter sesudah karakter terakhir yang diakuisisi }*/
