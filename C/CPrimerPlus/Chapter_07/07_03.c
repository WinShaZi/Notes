#include <stdio.h>
#include <stdlib.h>

int main()
{
	float aver = 0, unaver = 0;
	long sum = 0, unsum = 0, even = 0, uneven = 0;
	long num = 0;

	while (scanf("%ld", &num) == 1 && num != 0)
	{
		if ((num % 2) == 0)
		{
			even++;
			sum += num;
			aver = (float)sum / even;
		}
		else
		{
			uneven++;
			unsum += num;
			unaver = (float)unsum / uneven;
		}
	}
	printf("Even has %ld.\n", even);
	printf("Even average is %f.\n", aver);
	printf("Uneven has %ld.\n", uneven);
	printf("Unven average is %f.\n", unaver);

	system("pause");
	return 0;
}