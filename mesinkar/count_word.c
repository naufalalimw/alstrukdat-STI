#include "mesin_kar.h"
#include "boolean.h"

char CC;
boolean EOP;
static FILE *pita;

int main()
{
	int countword;
	countword = 0;
	char CC1, CC2;
	char inp[100];
	scanf("%s",&inp);
	START(inp);
	while (!IsEOP())
	{
		if (CC == 'd')
		{
			CC2 = CC;
			ADV();
			if (CC == 'o') 
			{
				CC1 = CC;
				ADV();
				if ((CC == 'r')&&(CC2 == 'd')&&(CC1=='o'))
				{
				countword = countword + 1;
				}
			}
		}
		ADV();
	} 
	printf("%d\n", countword);

	return 0;
}
