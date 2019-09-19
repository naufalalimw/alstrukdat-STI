/* File: jam.c */
/* Tanggal: 28 Agustus 2019 */
/* Implementasi ADT JAM */

#include <stdio.h>
#include "boolean.h"
#include "jam.h"

// Nama : Muhammad Rizky Ismail Faizal
// NIM  : 13518148

boolean IsJAMValid (int H, int M, int S) 
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    return (H>=0 && H<=23 && M>=0 && M<=59 && S>=0 && S<=59);
}

JAM MakeJAM (int HH, int MM, int SS) 
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
    JAM J;
    Hour(J) = HH;
    Minute(J) = MM;
    Second(J) = SS;
    return J;
}

void BacaJAM (JAM * J) 
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
    int j, m, s = -1;
    boolean check = false;
    while (!check) {
        scanf("%d %d %d", &j, &m, &s);
        check = IsJAMValid(j, m, s);
        if (!check) {
            printf("Jam tidak valid\n");
        }
    }
    Hour(*J) = j;
    Minute(*J) = m;
    Second(*J) = s;
}

void TulisJAM (JAM J) 
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */
{
    printf("%02d:%02d:%02d", Hour(J), Minute(J), Second(J));
}

long JAMToDetik (JAM J) 
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    return (Hour(J)*3600) + (Minute(J)*60) + Second(J);
}

JAM DetikToJAM (long N) 
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
    JAM J;
    if (N < 0) { N = 86400 + N; }
    N = N % 86400;
    Hour(J) = N / 3600;
    Minute(J) = (N % 3600) / 60;
    Second(J) = N % 60;
    return J;
}

boolean JEQ (JAM J1, JAM J2) 
/* Mengirimkan true jika J1=J2, false jika tidak */
{
    return (Hour(J1) == Hour(J2)) && (Minute(J1) == Minute(J2)) && (Second(J1) == Second(J2));
}

boolean JNEQ (JAM J1, JAM J2) 
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
    return (Hour(J1) != Hour(J2)) || (Minute(J1) != Minute(J2)) || (Second(J1) != Second(J2));
}

boolean JLT (JAM J1, JAM J2) 
/* Mengirimkan true jika J1<J2, false jika tidak */
{
    if (Hour(J1) < Hour(J2)) {
        return true;
    } else if (Hour(J1) > Hour(J2)) {
        return false;
    } else if (Minute(J1) < Minute(J2)) {
        return true;
    } else if (Minute(J1) > Minute(J2)) {
        return false;
    } else if (Second(J1) < Second(J2)) {
        return true;
    } else /*if (Second(J1) >= Second(J2))*/ {
        return false;
    }
}

boolean JGT (JAM J1, JAM J2) 
/* Mengirimkan true jika J1>J2, false jika tidak */
{
    if (Hour(J1) > Hour(J2)) {
        return true;
    } else if (Hour(J1) < Hour(J2)) {
        return false;
    } else if (Minute(J1) > Minute(J2)) {
        return true;
    } else if (Minute(J1) < Minute(J2)) {
        return false;
    } else if (Second(J1) > Second(J2)) {
        return true;
    } else /*if (Second(J1) <= Second(J2))*/ {
        return false;
    }
}

JAM NextDetik (JAM J) 
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
    return DetikToJAM(JAMToDetik(J)+1);
}

JAM NextNDetik (JAM J, int N) 
/* Mengirim N detik setelah J dalam bentuk JAM */
{
    return DetikToJAM(JAMToDetik(J)+N);
}

JAM PrevDetik (JAM J) 
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
    return DetikToJAM(JAMToDetik(J)-1);
}

JAM PrevNDetik (JAM J, int N) 
/* Mengirim N detik sebelum J dalam bentuk JAM */
{
    return DetikToJAM(JAMToDetik(J)-N);
}

long Durasi (JAM JAw, JAM JAkh) 
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
    if (JGT(JAw, JAkh)) {
        return (86400 - JAMToDetik(JAw)) + JAMToDetik(JAkh);
    } else {
        return JAMToDetik(JAkh) - JAMToDetik(JAw);
    }
}
