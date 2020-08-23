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
	printf("************************************************\n");
	printf("* Input your wage:                             *\n");
	printf("* a) $8.75                  b) $9.33           *\n");
	printf("* c) $10.00                 d) $11.20          *\n");
	printf("* q) quit                                      *\n");
	printf("************************************************\n");
}

int main()
{
	char wage = '\0';
	double sum = 0.0, hour = 0.0, tax = 0.0, money = 0.0;

	menu();

	while (scanf("%c", &wage, 1) == 1)
	{
		if (wage == '\n')
			continue;
		switch (wage)
		{
		case 'a':
			money = WAGE_1;
			break;
		case 'b':
			money = WAGE_2;
			break;
		case 'c':
			money = WAGE_3;
			break;
		case 'd':
			money = WAGE_4;
			break;
		case 'q':
			break;
		default:
			printf("Enter once again:");
		}
		if (wage == 'q')
			break;
		else if (wage <= 'd' && wage >= 'a')
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
				printf("Your total income is $%.2lf.\n", sum);
				printf("Your tax is $%.2lf.\n", tax);
				printf("Your net income is $%.2lf\n", sum - tax);
				printf("Input once again : ");
			}
		}
	}
	printf("Bye.\n");

	system("pause");
	return 0;
}