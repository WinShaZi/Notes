#include <stdio.h>
#include <stdlib.h>

#define MONEY_1 10
#define MONEY_2 15
#define TAXES_1 0.15
#define TAXES_2 0.2
#define TAXES_3 0.25
#define HOUR 40
#define SUM_1 300
#define SUM_2 150
#define SUM_3 450

int main()
{
	double sum = 0.0, hour = 0.0, tax = 0.0;

	printf("Input your work time of a week(h) : ");
	while (scanf("%lf", &hour) != 1)
	{
		printf("Input your work time of a week(h) : ");
		continue;
	}
	if (hour <= HOUR)
	{
		sum = hour * MONEY_1;
		if (sum <= SUM_1)
			tax = sum * TAXES_1;
		else
			tax = SUM_1 * TAXES_1 + (sum - SUM_1)*TAXES_2;
	}
	else
	{
		sum = HOUR * MONEY_1 + (hour - HOUR)*MONEY_2;
		if (sum <= SUM_3)
			tax = SUM_1 * TAXES_1 + (sum - SUM_1)*TAXES_2;
		else
			tax = SUM_1 * TAXES_1 + SUM_2 * TAXES_2 + (sum - SUM_3)*TAXES_3;
	}
	printf("YOUR total income is $%.2f.\n", sum);
	printf("Your tax is $%.2f.\n", tax);
	printf("Your net income is $%.2f.\n", sum - tax);

	system("pause");
	return 0;
}