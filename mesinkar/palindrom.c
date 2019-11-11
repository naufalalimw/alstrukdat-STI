#include "mesin_kata.h"
#include "boolean.h"
#include <stdio.h>
#include "mesin_kar.h"


boolean EndKata;
Kata CKata;
char CC;


int main()
{
	char inp[100];
	scanf("%s",&inp);
	STARTKATA(inp);
	boolean palindrom;
	int jumlah;
	jumlah = 0;
	while (!(EndKata))
	{
		for (int i = 1; i < (CKata.Length/2); ++i)
		{
			if (CKata.TabKata[i] == CKata.TabKata[((CKata.Length)+1) - i])
			{
				palindrom = true;
			}else{
				palindrom = false;
				break;
			}
			if (CKata.TabKata[((CKata.Length)/2)] == CKata.TabKata[((CKata.Length)+1) - ((CKata.Length)/2)])
			{
				jumlah += 1;
			}
		}
	ADVKATA();
	}
	printf("%d\n", jumlah);
	return 0;
}