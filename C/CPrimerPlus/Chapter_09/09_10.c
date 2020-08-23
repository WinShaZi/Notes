#include <stdio.h>
#include <stdlib.h>

void to_binary(unsigned long a, unsigned long b)
{
	int r = 0;

	r = a % b;
	if (a >= b)
		to_binary(a / b, b);
	printf("%lu", r);
}

int main()
{
	unsigned long a = 0, b = 0;

	printf("Enter two integers : ");
	while (scanf("%lu%lu", &a, &b) == 2)
	{
		if (b <= 10 && b >= 2)
		{
			printf("Binary equivalent : ");
			to_binary(a, b);
			putchar('\n');
			printf("Enter two integers : ");
		}
		else
			printf("Enter two integers : ");
	}
	printf("Done.\n");

	system("pause");
	return 0;
}