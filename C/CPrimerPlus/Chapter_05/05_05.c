#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 0, sum = 0, day = 0;

	printf("Input a number of days : ");
	while (scanf("%d", &day) == 1 && day >= 0)
	{
		for (num = 0, sum = 0; num <= day; num++)
			sum += num;
		printf("%d days you make $%d.\n", day, sum);
		printf("Next input : ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}