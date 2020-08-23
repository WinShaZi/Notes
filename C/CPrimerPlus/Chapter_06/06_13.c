#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int num[8] = {0}, n = 0;
	int i = 0, j = 0;

	for (n = 1; i < 8; i++, n++)
		num[i] = (int)pow(2, n);
	do
	{
		printf("%d\n", num[j]);
		j++;
	} while (j < 8);

	system("pause");
	return 0;
}