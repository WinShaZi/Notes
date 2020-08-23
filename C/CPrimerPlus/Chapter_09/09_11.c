#include <stdio.h>
#include <stdlib.h>

void Fibonacci(long long int days)
{
	long num, temp, i = 1, j = 1, k = 3;

	if (days == 1)
		printf("1 ");
	else if (days == 2)
		printf("1 1 ");
	else
	{
		printf("1 1 ");
		while (k <= days)
		{
			num = i + j;
			temp = i;
			i = num;
			j = temp;
			printf("%ld ", num);
			k++;
		}
	}
}

int main()
{
	long long int days;

	printf("What number do you need to get to : ");
	while (scanf("%lld", &days) == 1 && days > 0)
	{
		Fibonacci(days);
		printf("\nNext input:");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}