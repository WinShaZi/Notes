#include <stdio.h>
#include <stdlib.h>

int main()
{
	double inch = 0;
	double cm = 0;

	printf("Input the inches : ");
	scanf("%lf", &inch);
	cm = inch * 2.54;
	printf("%lf cm\n", cm);

	system("pause");
	return 0;
}