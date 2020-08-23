#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

big_small(int *num)
{
	int n = 0;
	int i = 0, j = 0;

	for (i = 0; i < SIZE - 1; i++)
		for (j = i + 1; j < SIZE; j++)
			if (num[i] < num[j])
			{
				n = num[i];
				num[i] = num[j];
				num[j] = n;
			}
	putchar('\n');
	for (i = 1; i <= SIZE; i++)
	{
		printf("%-6d", num[i - 1]);
		if (i % 10 == 0)
			putchar('\n');
	}
}

int main()
{
	int count = 0;
	int num[SIZE] = {0};
	int max = 0, min = 0;

	srand((unsigned int)time(NULL));
	printf("Input max and min value : ");
	while (scanf("%d %d", &max, &min) == 2)
	{
		if (max <= min)
			continue;
		for (count = 0; count < SIZE; count++)
			num[count] = rand() % (max + 1 - min) + min;

		for (count = 1; count <= SIZE; count++)
		{
			printf("%-6d", num[count - 1]);
			if (count % 10 == 0)
				putchar('\n');
		}
		big_small(num);
		printf("Next input : ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}