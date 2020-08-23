#include <stdio.h>
#include <stdlib.h>

int main()
{
	int max = 0, min = 0, sum = 0;

	printf("Input lower and upper integer limits : ");
	while (scanf("%d%d", &min, &max) == 2 && min < max)
	{
		for (sum = 0; min <= max; min++)
			sum += min * min;
		printf("The sums of squares is %d.\n", sum);
		printf("Next input : ");
	}
	printf("Done.\n");

	system("pause");
	return 0;
}