#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int main()
{
	char st_1[SIZE] = "\0";
	char st_2[SIZE] = "\0";
	double sum = 1, x = 0;
	int i = 0, n = 0;

	gets_s(st_1, SIZE);
	gets_s(st_2, SIZE);
	x = atof(&st_1[0]);
	n = atoi(&st_2[0]);

	for (i = 0; i < n; i++)
		sum *= x;
	printf("%lf ^ %d = %lf\n", x, n, sum);

	system("pause");
	return 0;
}