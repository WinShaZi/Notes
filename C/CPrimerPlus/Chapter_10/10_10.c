#include <stdio.h>
#include <stdlib.h>

show_ar(int i, int ar[])
{
	for (i = 0; i < 4; i++)
	{
		printf(" %d", *(ar + i));
		if (i < 3)
			putchar(',');
	}
	printf(" }\n");
}

int main()
{
	int x[4] = { 1,2,3,4 };
	int y[4] = { 4,3,2,1 };
	int z[4] = {0};
	int i = 0;

	for (i = 0; i < 4; i++)
		z[i] = x[i] + y[i];

	printf("x[4] = {");
	show_ar(i, x);

	printf("y[4] = {");
	show_ar(i, y);

	printf("z[4] = {");
	show_ar(i, z);

	system("pause");
	return 0;
}