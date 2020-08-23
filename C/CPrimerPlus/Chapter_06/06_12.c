#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0, i = 0, j = 0;
	double sum_1 = 0.0, sum_2 = 0.0;

	printf("Input an integer(n>0) : ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		sum_1 += 1.0 / i;
	for (j = 1; j <= n; j++)
	{
		if (j % 2 == 0)
			sum_2 -= 1.0 / j;
		else
			sum_2 += 1.0 / j;
	}
	printf("The num_1: %lf\n", sum_1);
	printf("The num_2: %lf\n", sum_2);

	system("pause");
	return 0;
}