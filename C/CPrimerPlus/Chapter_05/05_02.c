#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x1 = 0, x2 = 0;

	printf("Input a number : ");
	while (scanf("%d", &x1) == 1)
	{
		for (x2 = x1 + 10; x1 <= x2; x1++)
			printf("%d ", x1);
		printf("\n");
		printf("Next input : ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}