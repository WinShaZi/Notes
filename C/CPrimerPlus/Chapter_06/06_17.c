#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	double i = 100.0;

	do
	{
		i += 0.08 * i;
		i -= 10;
		n++;
	} while (i > 0);
	printf("%d years.\n", n);

	system("pause");
	return 0;
}