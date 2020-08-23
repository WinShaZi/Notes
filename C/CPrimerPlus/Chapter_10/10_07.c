#include <stdio.h>
#include <stdlib.h>

show_ar(double ar[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		printf("  {");
		for (j = 0; j < 3; j++)
		{

			printf(" %.1lf", ar[i][j]);
			if (j < 2)
				putchar(',');
		}
		printf(" }");
		if (i < 2)
			putchar(',');
		putchar('\n');
	}
	printf("}\n");
}

int main()
{
	double num[3][3] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	double copy_num[3][3] = {0};
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			copy_num[i][j] = num[i][j];

	printf("num[3][3] = \n{\n");
	show_ar(num);

	printf("copy_num[3][3] = \n{\n");
	show_ar(copy_num);

	system("pause");
	return 0;
}