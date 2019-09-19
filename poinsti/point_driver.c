/* Nama File : point_driver.c*/
/* Tanggal 04 September 2019*/
/* Implementasi ADT Point */

#include "point.h"
#include <stdio.h>
int main (){
    POINT P1 , P2;
    P2 = MakePOINT(2.34,6.75);
    BacaPOINT(&P1);
    TulisPOINT (P1);
    Geser (&P1,2.3,4.5);
    printf ("\nEQ: %d\n",EQ(P1,P2));
    return 0;
}
