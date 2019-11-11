#include "stack.h"
#include <stdio.h>

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    (*S).TOP = Nil;
}
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Stack S)
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
{
    return (S.TOP==Nil);
}
bool IsFull(Stack S)
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
{
    return (S.TOP ==MaxEl);
}
/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
    (*S).TOP++;
    (*S).T[(*S).TOP-1] = X;
}
void Pop (Stack *S, infotype *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X) = (*S).T[(*S).TOP-1];
    (*S).TOP--;
}
