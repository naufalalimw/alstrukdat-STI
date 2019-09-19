// Nama : Muhammad Rizky Ismail Faizal
// NIM  : 13518148

#include <stdio.h>
#include "jam.h"

int main() {
    // Kamus
    long n;
    JAM J1;
    JAM J2;

    // Algoritma
    printf("Masukkan jam: ");
    BacaJAM(&J1);
    TulisJAM(J1);
    printf("\nTotal detik: %ld\n", JAMToDetik(J1));
    printf("Masukkan detik: ");
    scanf("%ld", &n);
    J2= DetikToJAM(n);
    printf("Durasi: %ld detik", Durasi(J1, J2));
}
