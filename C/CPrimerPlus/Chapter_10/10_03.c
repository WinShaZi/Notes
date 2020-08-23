#include <stdio.h>
#include <stdlib.h>

int MAX(int num[])
{
	int i = 0, max = num[0];

	for (i = 0; i < 9; i++)
	{
		if (max < num[i + 1])
			max = num[i + 1];
	}

	return max;
}

int main()
{
	int i = 0;
	int num[10] = {0};

	printf("Input 10 number : ");
	for (i = 0; i < 10; i++)
		scanf("%d", &num[i]);

	printf("num[10] = { ");
	for (i = 0; i < 10; i++)
	{
		printf(" %d", num[i]);
		if (i < 9)
			putchar(',');
	}
	printf(" }\n");
	printf("The max number is %d.\n", MAX(num));

	system("pause");
	return 0;
}