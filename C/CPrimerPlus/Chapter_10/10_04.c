#include <stdio.h>
#include <stdlib.h>

int MAX(double num[])
{
	int i = 0, max = 0;

	for (i = 0; i < 9; i++)
	{
		if (num[max] < num[i + 1])
			max = i + 1;
	}

	return max;
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

	printf("The max number is num[%d] = %.1lf\nThe array index is %d\n", MAX(num), num[MAX(num)], MAX(num));

	system("pause");
	return 0;
}