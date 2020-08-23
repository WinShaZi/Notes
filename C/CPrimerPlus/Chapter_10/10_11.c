#include <stdio.h>
#include <stdlib.h>

show_ar(int ar[][5], int n)
{
	int i = 0, j = 0;

	for (i = 0; i < n; i++)
	{
		printf("  {");
		for (j = 0; j < 5; j++)
		{
			printf(" %d", *(*(ar + i) + j));
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
	int i = 0, j = 0;
	int num_1[3][5] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};
	int num_2[3][5] = {0};

	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			num_2[i][j] = 2 * num_1[i][j];

	printf("num_1[3][5] =\n{\n");
	show_ar(num_1, 3);
	printf("num_2[3][5] =\n{\n");
	show_ar(num_2, 3);

	system("pause");
	return 0;
}