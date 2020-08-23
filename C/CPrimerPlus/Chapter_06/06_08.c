#include <stdio.h>
#include <stdlib.h>

int main()
{
	float a = 0, b = 0;

	printf("Input two floating point value : ");
	while (scanf("%f%f", &a, &b) == 2)
	{
		printf("%f\n", (a - b) / (a*b));
		printf("Next input:");
	}

	system("pause");
	return 0;
}