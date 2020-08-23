#include <stdio.h>
#include <stdlib.h>

int main()
{
	float num = 0;

	printf("Input a floating point value : ");
	scanf("%f", &num);
	printf("The input is %.1f or %.1e.\n", num, num);
	printf("The input is %.3f or %.3E.\n", num, num);

	system("pause");
	return 0;
}