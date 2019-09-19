#include <stdio.h>
#include "array.h"
#include "boolean.h"

int main()
{
	TabInt T;
	int a,min,max;	
	scanf ("%d",&a);
	while ((a<=0)||(a>IdxMax))
	{
		scanf ("%d",&a);
	}
	T.Neff = a;
	for (int i = IdxMin; i <= T.Neff; i++)
	{
		scanf ("%d", &T.TI[i]);
			}
	min = T.TI[IdxMin];
	for (int i = IdxMin+1; i <= T.Neff; ++i)
	{
		if (min>=T.TI[i])
		{
			min = T.TI[i];
		}
	}
	max = T.TI[IdxMin];
	for (int i = IdxMin+1; i <= T.Neff; ++i)
	{
		if (max<=T.TI[i])
		{
			max = T.TI[i];
		}
	}
	printf("[");
	for (int i = IdxMin; i <= T.Neff; i++) {
		printf("%d",T.TI[i]);
		if (i<T.Neff) printf(",");
	}
	printf ("]\n");
	printf("%d\n%d\n", min, max );
} 

