#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double number(double n)
{
	return pow(n, 3);
}

int main()
{
	int n = 0;

	printf("Input a number : ");
	while (scanf("%lf", &n) == 1)
	{
		printf("%d to third power is %lf\n", n, number(n));
		printf("Next input : ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}