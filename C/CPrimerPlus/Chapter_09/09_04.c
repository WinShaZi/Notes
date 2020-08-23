#include <stdio.h>
#include <stdlib.h>

double min_1(double x, double y)
{
	return 2 * x * y / (x + y);
}

int main()
{
	double x = 0, y = 0, aver = 0;

	printf("Input two double floating point numbers : ");
	scanf("%lf%lf", &x, &y);
	aver = min_1(x, y);
	printf("%lf\n", aver);

	system("pause");
	return 0;
}