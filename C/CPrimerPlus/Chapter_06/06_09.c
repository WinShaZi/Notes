#include <stdio.h>
#include <stdlib.h>

float num(float a, float b)
{
	return (a - b) / (a * b);
}

int main()
{
	float a = 0, b = 0;

	printf("Input two floating point value : ");
	while (scanf("%f%f", &a, &b) == 2)
	{
		printf("%f\n", num(a, b));
		printf("Next input : ");
	}

	system("pause");
	return 0;
}