#include <stdio.h>
#include <stdlib.h>

double min_max(double x, double y)
{
	return x < y ? x : y;
}

int main()
{
	double x = 0, y = 0;

	printf("Input two double floating point value : ");
	if (scanf("%lf%lf", &x, &y) == 2 && x != y)
	{
	    min_max(x, y);
		printf("%lf\n", min_max(x, y));
	}
	else
		printf("Done!\n");

	system("pause");
	return 0;
}