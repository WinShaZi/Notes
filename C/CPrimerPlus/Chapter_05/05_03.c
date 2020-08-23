#include <stdio.h>
#include <stdlib.h>

#define WEEK_DAY 7

int main()
{
	int day = 0, week = 0, time = 0;

	printf("Input the number of days : ");
	while (scanf("%d", &time) == 1 && time >= 0)
	{
		week = time / WEEK_DAY;
		day = time % WEEK_DAY;
		printf("%d days is %d weeks and %d days.\n", time, week, day);
		printf("Next input : ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}