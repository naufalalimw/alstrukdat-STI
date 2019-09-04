/* File : point.c */
/* Tanggal 04 September 2019*/
/* Implementasi ADT Point */

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
{
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT *P)
{
    scanf("%f %f", &Absis(*P), &Ordinat(*P));
}
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P)
{
    printf("%.2f %.2f", Absis(P), Ordinat(P));
}
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
{
    return ((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2)
{
    return !EQ(P1,P2);
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
{
    return((Absis(P)==0)&&(Ordinat(P)==0));
}
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P)
{
    return(Ordinat(P)==0);
}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P)
{
    return(Absis(P)==0);
}
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P)
{
    if (Absis(P)>0)
    {
        if (Ordinat(P)>0)
        {
            return 1;
        }
        else /*ordinat(P)<0*/
        {
            return 3;
        }
        
    }
    else //Absis(P)<0
    {
        if (Ordinat(P)>0)
        {
            return 2;
        }
        else /*ordinat(P)<0*/
        {
            return 4;
        }   
    }
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
    return MakePOINT(Absis(P)+1, Ordinat(P));
}
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY (POINT P){
        return MakePOINT(Absis(P), Ordinat(P)+1);
}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, float deltaX, float deltaY){
        return MakePOINT(Absis(P)+deltaX, Ordinat(P)+deltaY);
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
POINT MirrorOf (POINT P, boolean SbX){
    if (SbX)
    {
            return MakePOINT(Absis(P), -Ordinat(P));
    }
    else
    {
            return MakePOINT(-Absis(P), Ordinat(P));
    }
    
}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
float Jarak0 (POINT P){
    return sqrtf(Absis(P)*Absis(P)+(Ordinat(P)*Ordinat(P)));
}
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2)
{
    float A = Absis(P1)-Absis(P2);
    float B = Ordinat(P1)- Ordinat(P2);
    return sqrtf(A*A + B*B);
}
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
void Geser (POINT *P, float deltaX, float deltaY)
{
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void GeserKeSbX (POINT *P){
    Absis(*P) = 0;
}
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P){
    Ordinat(*P)=0;
}
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void Mirror (POINT *P, boolean SbX){
    if (SbX)
    {
        Absis(*P),-Ordinat(*P);
    }
    else //SbX == false
    {
        MakePOINT(-Absis(*P),Ordinat(*P));
    }
    
}
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */

void Putar (POINT *P, float Sudut){
    POINT temp=*P;
    float rad = -Sudut/180*3.14;
    Absis(temp)=cos(rad)*(Absis(*P))-sin(rad)*(Ordinat(*P));
    Ordinat(temp)=sin(rad)*(Absis(*P))-cos(rad)*(Ordinat(*P));
    *P=temp;
}

/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/