#include <stdio.h>
#include <stdlib.h>

#define TAX_1 0.15
#define TAX_2 0.28
#define MARRY_1 17850
#define MARRY_2 23900
#define MARRY_3 29750
#define MARRY_4 14875

void menu()
{
	printf("******************************************************\n");
	printf("* Choose your marital status:                        *\n");
	printf("* 1) Bachelordom         2) Head of a household      *\n");
	printf("* 3) Married             4) Divorce                  *\n");
	printf("* 5) Quit                                            *\n");
	printf("******************************************************\n");
}

int main()
{
	int marry;
	double money = 0.0, tax = 0.0;

	menu();

	while (scanf("%d", &marry) == 1 && marry != 5)
	{
		if (marry > 5 || marry < 1)
		{
			printf("Choose your marital status once again : ");
			continue;
		}
		printf("Input your tatol income : ");
		if (scanf("%lf", &money) != 1)
		{
			printf("Choose your marital status once again : ");
			continue;
		}
		switch (marry)
		{
		case 1:
			if (money <= MARRY_1)
				tax = money * TAX_1;
			else
				tax = (money - MARRY_1) * TAX_2 + MARRY_1 * TAX_1;
			break;
		case 2:
			if (money <= MARRY_2)
				tax = money * TAX_1;
			else
				tax = (money - MARRY_2) * TAX_2 + MARRY_2 * TAX_1;
			break;
		case 3:
			if (money <= MARRY_3)
				tax = money * TAX_1;
			else
				tax = (money - MARRY_3) * TAX_2 + MARRY_3 * TAX_1;
			break;
		case 4:
			if (money <= MARRY_4)
				tax = money * TAX_1;
			else
				tax = (money - MARRY_4) * TAX_2 + MARRY_4 * TAX_1;
			break;
		default:
			printf("Choose your marital status once again : ");
		}
		printf("Your tax is $%.2f.\n", tax);
		menu();
	}

	printf("Done!\n");

	system("pause");
	return 0;
}