#include <stdio.h>
#include <stdlib.h>

void chLine(int i, int j)
{
	int a = 0, b = 0;

	for (a = 0; a < j; a++)
	{
		for (b = 0; b < i; b++)
			putchar('$');
		putchar('\n');
	}
}

int main()
{
	int i = 0, j = 0;

	printf("Enter the number of column and line : ");
	if (scanf("%d%d", &i, &j) == 2)
		chLine(i, j);
	else
		printf("Done!\n");

	system("pause");
	return 0;
}