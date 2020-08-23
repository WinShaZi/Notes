#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 5, i = 0;

	do
	{
		i++;
		n -= i;
		n *= 2;
		printf("%d weeks have %d friends.\n", i, n);
	} while (n < 150);
	printf("Done!\n");

	system("pause");
	return 0;
}