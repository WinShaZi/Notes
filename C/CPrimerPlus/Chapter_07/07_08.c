#include <stdio.h>
#include <stdlib.h>

#define TAXES_1 0.15
#define TAXES_2 0.2
#define TAXES_3 0.25
#define WAGE_1 8.75
#define WAGE_2 9.33
#define WAGE_3 10.00
#define WAGE_4 11.20
#define HOUR 40
#define OVER_TIME 1.5
#define SUM_1 300
#define SUM_2 450

void menu()
{
	printf("**********************************************\n");
	printf("* Input your wage:                           *\n");
	printf("* 1) $8.75                  2) $9.33         *\n");
	printf("* 3) $10.00                 4) $11.20        *\n");
	printf("* 5) quit                                    *\n");
	printf("**********************************************\n");
}

int main()
{
	int wage;
	double sum = 0.0, hour = 0.0, tax = 0.0, money = 0.0;

	menu();

	while (scanf("%d", &wage) == 1)
	{
		switch (wage)
		{
		case 1:
			money = WAGE_1;
			break;
		case 2:
			money = WAGE_2;
			break;
		case 3:
			money = WAGE_3;
			break;
		case 4:
			money = WAGE_4;
			break;
		case 5:
			break;
		default:
			printf("Enter once again : ");
		}
		if (wage == 5)
			break;
		else if (wage <= 4 && wage >= 1)
		{
			printf("Input your work time of a week : ");
			if (scanf("%lf", &hour) == 1 && hour >= 0)
			{
				if (hour <= HOUR)
				{
					sum = hour * money;
					if (sum <= SUM_1)
						tax = sum * TAXES_1;
					else
						tax = SUM_2 * TAXES_1 + (sum - SUM_1)*TAXES_2;
				}
				else
				{
					sum = HOUR * money + (hour - HOUR) * money*OVER_TIME;
					if (sum <= SUM_2)
						tax = SUM_1 * TAXES_1 + (sum - SUM_1) * TAXES_2;
					else
						tax = SUM_1 * TAXES_1 + (SUM_2 - SUM_1) * TAXES_2 + (sum - SUM_2)*TAXES_3;
				}
				printf("Your total income is $%.2f.\n", sum);
				printf("Your tax is $%.2f.\n", tax);
				printf("Your net income is $%.2f\n", sum - tax);
				printf("Input once again : ");
			}
		}
	}
	printf("Bye.\n");

	system("pause");
	return 0;
}