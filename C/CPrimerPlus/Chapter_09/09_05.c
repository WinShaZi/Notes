#include <stdio.h>
#include <stdlib.h>

larger_of(double *x, double *y)
{
	*x > *y ? (*y = *x) : (*y = *y);
}

int main()
{
	double a = 0, b = 0;

	do
	{
		printf("Input two number : ");
		scanf("%lf %lf", &a, &b);
	} while (a == b);
	larger_of(&a, &b);
	printf("%lf  %lf\n", a, b);

	system("pause");
	return 0;
}