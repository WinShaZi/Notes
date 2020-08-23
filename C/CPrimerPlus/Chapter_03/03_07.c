#include <stdio.h>
#include <stdlib.h>

int main()
{
	double inch = 0, centimeter = 0;

	printf("Input your height(in) : ");
	scanf("%lf", &inch);
	centimeter = inch * 2.54;
	printf("Your height is %.2lf CM.\n", centimeter);

	system("pause");
	return 0;
}