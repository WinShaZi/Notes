#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0, j = 0;
	char ch = 'A';

	for (i = 1; i <= 6; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%c", ch++);
		printf("\n");
	}

	system("pause");
	return 0;
}