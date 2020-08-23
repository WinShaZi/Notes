#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0, j = 0;
	double abc[10] = {0}, cba[10] = {0};

	printf("Input 10 number : ");
	for (i = 0; i < 10; i++)
		scanf("%lf", &abc[i]);

	printf("abc[10] = { ");
	for (i = 0; i < 10; i++)
	{
		printf(" %.1lf", abc[i]);
		if (i < 9)
			putchar(',');
	}
	printf(" }\n");

	printf("cba[10] = { ");
	for (i = 0, j = 9; i < 10; i++, j--)
	{
		cba[i] = abc[j];
		printf(" %.1lf", cba[i]);
		if (i < 9)
			putchar(',');
	}
	printf(" }\n");

	system("pause");
	return 0;
}