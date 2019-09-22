#include "mesin_kar.h"
#include "boolean.h"

char CC;
boolean EOP;
static FILE *pita;

int main()
{
	int countcar;
	countcar = 0;
	char inp[100];
	scanf("%s\n",inp);
	START(inp);
	while (!IsEOP())
	{
		if (CC == 'e')
		{
			countcar = countcar + 1;
		}
		ADV();
	} 
	printf("%d\n", countcar);

	return 0;
}

