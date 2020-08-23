#include <stdio.h>
#include <stdlib.h>

double power(double n, int p)
{
	if (n == 0)
	{
		if (p == 0)
		{
			printf("Error!\n");
			return 1;
		}
		return 0;
	}
	if (p == 0)
		return 1;
	if (p > 0)
		return n * power(n, p - 1);
	else
		return 1 / n * power(n, p + 1);
}

int main()
{
	double n = 0;
	int p = 0;

	printf("Enter a number and the positive integer power to which : ");
	while (scanf("%lf%d", &n, &p) == 2)
	{
		printf("%lf to the power %d is %lf\n", n, p, power(n, p));
		printf("Enter next pair of numbers : ");
	}
	printf("bye!\n");

	system("pause");
	return 0;
}