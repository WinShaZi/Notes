#include <stdio.h>
#include <stdlib.h>

min_max(double *x, double *y, double *z)
{
	double a = 0, b = 0, c = 0;

	a = *x;
	b = *y;
	c = *z;

	if (a < c)
	{
		if (a < b)
		{
			if (c < b)
			{
				*x = a;
				*y = c;
				*z = b;
			}
			else
			{
				*x = a;
				*y = b;
				*z = c;
			}
		}
		else
		{
			*x = b;
			*y = a;
			*z = c;
		}
	}
	else
	{
		if (a < b)
		{
			*x = c;
			*y = a;
			*z = b;
		}
		else
		{
			if (c < b)
			{
				*x = c;
				*y = b;
				*z = a;
			}
			else
			{
				*x = b;
				*y = c;
				*z = a;
			}
		}
	}
}

int main()
{
	double x, y, z;

	do
	{
		printf("Input three double floating point numbers : ");
		scanf("%lf%lf%lf", &x, &y, &z);
	} while (x == y || x == z || y == z);
	min_max(&x, &y, &z);
	printf("%lf\n%lf\n%lf\n", x, y, z);

	system("pause");
	return 0;
}