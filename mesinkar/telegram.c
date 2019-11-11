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

	int harga, countword;
	harga = 0;
	countword = 0;
	while (!(EndKata))
	{
		if (CKata.Length > 10)
		{
			harga = harga + 1500;
			countword += 1;
		}else if (CKata.Length>0 && CKata.Length <= 10)
		{
			harga = harga + 1000;
			countword = countword + 1;
		}
		ADVKATA();
	}
	if (countword > 10)
	{
		printf("%d\n", harga+200 );
	}else 
	{
		printf("%d\n", harga );
	}
	return 0;
}