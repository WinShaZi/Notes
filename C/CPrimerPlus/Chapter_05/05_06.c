#include <stdio.h>
#include <stdlib.h>

int main()
{
	double num = 0, sum = 0;
	int day = 0;

	printf("Input a number of days : ");
	while (scanf("%lf", &day) == 1 && day >= 0)
	{
		for (num = 0, sum = 0; num <= day; num++)
			sum += num * num;
		printf("%d days you make $%.1lf.\n", day, sum);
		printf("Next input : ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}