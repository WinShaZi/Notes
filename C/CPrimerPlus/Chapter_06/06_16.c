#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	double x1 = 100.0, x2 = 100.0;

	do
	{
		x1 += 10.0;
		x2 *= 1.05;
		n++;
	} while (x1 >= x2);
	printf("%d years.\n", n);
	printf("Daphne have $%.2f.\n", x1);
	printf("Deirdre have $%.2f.\n", x2);

	system("pause");
	return 0;
}