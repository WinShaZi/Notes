#include <stdio.h>
#include <stdlib.h>

int main()
{
	float num = 0;

	printf("Input a floating-point value : ");
	scanf("%f", &num);
	printf("fixed-point notation: %f\n", num);
	printf("exponential notation: %e\n", num);
	printf("p notation: %a\n", num);

	system("pause");
	return 0;
}