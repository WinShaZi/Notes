#include <stdio.h>
#include <stdlib.h>

copy(int ar1[][5], int ar2[][5], int n)
{
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < 5; j++)
			*(*(ar1 + i) + j) = *(*(ar2 + i) + j);
}

show_ar(int ar[][5], int n)
{
	int i = 0, j = 0;

	for (i = 0; i < n; i++)
	{
		printf("  {");
		for (j = 0; j < 5; j++)
		{
			printf(" %d", ar[i][j]);
			if (j < 4)
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
	int num[3][5] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};
	int copy_num[3][5];

	copy(copy_num, num, 3);
	printf("num[3][5] =\n{\n");
	show_ar(num, 3);
	printf("copy_num[3][5] =\n{\n");
	show_ar(copy_num, 3);

	system("pause");
	return 0;
}