#include <stdio.h>
#include <stdlib.h>

double power(double n, int p)
{
	double pow = 1, num = 1;
	int i = 0;

	if (n == 0)
		pow = 0;
	else
	{
		if (p > 0)
			for (i = 1; i <= p; i++)
				pow *= n;
		else if (p < 0)
		{
			for (; p < 0; p++)
				num *= n;
			pow = 1 / num;
		}
		else
			pow = 1;
	}

	return pow;
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