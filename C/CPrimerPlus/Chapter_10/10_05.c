#include <stdio.h>
#include <stdlib.h>

double max_min(double num[])
{
	int i = 0;
	double max = num[0], min = num[0];

	for (i = 0; i < 9; i++)
	{
		if (max < num[i + 1])
			max = num[i + 1];
	}

	for (i = 0; i < 9; i++)
	{
		if (min > num[i + 1])
			min = num[i + 1];
	}

	return max - min;
}

int main()
{
	int i = 0;
	double num[10] = {0};

	printf("Input 10 number : ");
	for (i = 0; i < 10; i++)
		scanf("%lf", &num[i]);

	printf("num[10] = { ");
	for (i = 0; i < 10; i++)
	{
		printf(" %.1lf", num[i]);
		if (i < 9)
			putchar(',');
	}
	printf(" }\n");

	printf("The difference between a maximum and a minimum: %.1lf\n", max_min(num));

	system("pause");
	return 0;
}