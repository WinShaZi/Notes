#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	unsigned long long num = 0, prime = 0, i = 0, count = 0;
	bool mode = true;

	printf("Input a positive integer : ");
	while (scanf("%llu", &num) == 1)
	{
		count = 0;
		if (num < 2)
			printf("Error.\n");
		else
		{
			for (prime = 2; prime <= num; prime++)
			{
				for (i = 2, mode = true; (i * i) <= prime; i++)
					if ((prime % i) == 0)
						mode = false;
				if (mode)
				{
					printf("%llu is prime.\n", prime);
					count++;
				}
			}
		}
		printf("Here are %llu prime\n", count);
		printf("Input once again : ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}