#include <stdio.h>
#include "array.h"
#include "boolean.h"

int main()
{
	TabInt T;
	int a;
	scanf ("%d", &a);
	for (int i = IdxMin; i <= a; ++i)
	{
		scanf("%d", &T.TI[i]);
	}
	int b,i,c,d;
	b = T.TI[IdxMin];
	i = IdxMin;
	c = IdxMin;
	d = IdxMin;
	while (b == T.TI[i] && i<a)
	{
		i = i + 1;
	}
	while (b<= T.TI[c] && c<a) 
	{
		c = c + 1;
	}
	while (b >= T.TI[d] && d<a)
	{
		d = d + 1;
	}
	
	if (i==a)
	{
		printf("Array monotonik statik\n");
	} else if((d==a)&&(i!=a))
	{
		printf("Array monotonik tidak membesar\n");
	}else if ((c==a)&&(i!=a))
	{
		printf("Array monotonik tidak mengecil\n");
	}else if (c != 0 && d != 0)
	{
		printf ("Array tidak monotonik\n");
	}
	
	return 0;
}

// int lebihBesar = 0;
// int lebihKecil = 0;

// for (int i = IdxMin; i < a - 1; i++)
// {
// 	if (T.TI[i] > T.TI[i + 1]) {
// 		lebihKecil++;
// 	} else if (T.TI[i] < T.TI[i + 1])
// 	{
// 		lebihBesar++;
// 	}

// 	if (lebihBesar != 0 && lebihKecil != 0)
// 	{
// 		tidak monotonik
// 	}
	
	
// }

