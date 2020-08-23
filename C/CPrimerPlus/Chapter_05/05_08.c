#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num_1 = 0, num_2 = 0;

	printf("This program computes moduli.\n");
	printf("Enter an integer to save as the second operad : ");
	while (scanf("%d", &num_2) == 1 && num_2 <= 0)
		printf("Enter an integer to save as the second operad : ");
	if (num_2 > 0)
	{
		printf("Now enter the first operand(<=0 to quit) : ");
		while (scanf("%d", &num_1) == 1 && num_1 > 0)
		{
			printf("%d %% %d = %d\n", num_1, num_2, num_1 % num_2);
			printf("Enter next number for first operand(<=0 to quit) : ");
		}
	}
	printf("Done!\n");

	system("pause");
	return 0;
}