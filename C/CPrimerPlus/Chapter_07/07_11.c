#include<stdio.h>
#include<stdlib.h>

#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09
#define DISCOUNT 0.05
#define FREIGHT_1 6.5
#define FREIGHT_2 14
#define FREIGHT_3 0.5
#define QUALIT_1 5 
#define QUALIT_2 20

void menu()
{
	printf("*******************************************************\n");
	printf("*                       WELCOME                       *\n");
	printf("* What do you want to buy ?                           *\n");
	printf("* a) Artichoke $2.05/LB        b) Beet $1.15/LB       *\n");
	printf("* c) Carrot $1.09/LB           d) Settle accounts     *\n");
	printf("*******************************************************\n");
}

int main()
{
	int mode = 0;
	char ch;
	double sum = 0.0;
	double price = 0.0;
	double p_artichoke = 0.0, p_beet = 0.0, p_carrot = 0.0;
	double qualit = 0.0;
	double q_artichoke = 0.0, q_beet = 0.0, q_carrot = 0.0;
	double discount = 0.0;
	double freight = 0.0;

	menu();

	while (scanf("%c", &ch, 10) != EOF)
	{
		if (ch == '\n')
			continue;
		switch (ch)
		{
		case 'a':
			printf("How many do you want : ");
			if (scanf("%lf", &q_artichoke) != 1)
			{
				ch = 'd';
				break;
			}
			p_artichoke = ARTICHOKE * q_artichoke;
			qualit += q_artichoke;
			price += p_artichoke;
			printf("Price is $%.2f\n", price);
			printf("Do you want anything else ? : ");
			mode = 1;
			break;

		case 'b':
			printf("How many do you want : ");
			if (scanf("%lf", &q_beet) != 1)
			{
				ch = 'd';
				break;
			}
			p_beet = BEET * q_beet;
			qualit += q_beet;
			price += p_beet;
			printf("Price is $%.2lf\n", price);
			printf("Do you want anything else ? : ");
			mode = 1;
			break;

		case 'c':
			printf("How many do you want : ");
			if (scanf("%lf", &q_carrot) != 1)
			{
				ch = 'd';
				break;
			}
			p_carrot = CARROT * q_carrot;
			qualit += q_carrot;
			price += p_carrot;
			printf("Price is $%.2lf\n", price);
			printf("Do you want anything else ? : ");
			mode = 1;
			break;

		case 'd':
			break;
		default:
			printf("Enter once again : ");
		}

		if (ch == 'd')
			break;
	}

	if (price >= 100)
	{
		discount = price * DISCOUNT;
		freight = FREIGHT_2 + FREIGHT_3 * (qualit - QUALIT_2);
		sum = price - discount + freight;
	}

	else if (price == 0)
	{
		freight = 0.0;
		sum = 0.0;
	}

	else
	{
		if (qualit <= QUALIT_1 && qualit > 0)
		{
			freight = FREIGHT_1;
			sum = price + freight;
		}

		else if (qualit <= QUALIT_2 && qualit > QUALIT_1)
		{
			freight = FREIGHT_2;
			sum = price + freight;
		}

		else
		{
			freight = FREIGHT_2 + FREIGHT_3 * (qualit - QUALIT_2);
			sum = price + freight;
		}
	}

	if (mode == 1)
	{
		printf("You spend $%.2lf.\n", sum);
		printf("Price is $%.2lf.\n", price);
		printf("Freight is $%.2lf.\n", freight);
		printf("Discount is $%.2lf.\n", discount);
	}
	printf("You are welcome to come again.\n");

	system("pause");
	return 0;
}