// Nama : Naufal Alim Wahib
// Tanggal : 2 Oktober 2019
// Nama File : postfix.c

#include <stdio.h>
#include "stack.h"
#include "mesin_kata.h"

boolean EndKata;
Kata CKata;

int main()
{
    Stack S;
    int i,t;
    char post[100];
    
    scanf("%s", &post);
    CreateEmpty(&S);
    STARTKATA(post);

    while (!(EndKata))
    {
        Push(&S, CKata.TabKata[i]);
        
    }
    
}