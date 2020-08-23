#include <stdio.h>
#include <stdlib.h>

#define HOUR_MINUTE 60

int main()
{
	int min = 0, hour = 0, time = 0;

	printf("Input the number of minutes : ");
	while (scanf("%d", &time) == 1 && time >= 0)
	{
		hour = time / HOUR_MINUTE;
		min = time % HOUR_MINUTE;
		printf("%d minutes is %d hours and %d minutes.\n", time, hour, min);
		printf("Next input : ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}