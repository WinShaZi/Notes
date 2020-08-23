#include <stdio.h>
#include <stdlib.h>

int main()
{
	int toes = 0, toes2 = 0, toes_2 = 0;

	toes = 10;
	toes2 = 2 * toes;
	toes_2 = toes * toes;
	printf("toes = %d\n", toes);
	printf("toes * 2 = %d\n", toes2);
	printf("toes * toes = %d\n", toes_2);

	system("pause");
	return 0;
}