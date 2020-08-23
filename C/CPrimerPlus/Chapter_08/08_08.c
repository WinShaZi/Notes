#include <stdio.h>
#include <stdlib.h>

void menu()
{
	printf("Enter the operation of your choice:\n");
	printf("a. add             s. subtract\n");
	printf("m. multiply        d. divide\n");
	printf("q. quit\n");
}

double return_x()
{
	double x;
	char ch_1;

	printf("Enter first number : ");
	while (scanf("%lf", &x) != 1)
	{
		while ((ch_1 = getchar()) != '\n')
		{
			putchar(ch_1);
		}
		printf(" is not an number.\n");
		printf("Please enter a number : ");
	}
	return x;
}

double return_y()
{
	double y;
	char ch_2;

	printf("Enter second number : ");
	while (scanf("%lf", &y) != 1)
	{
		while ((ch_2 = getchar()) != '\n')
		{
			putchar(ch_2);
		}
		printf(" is not an number.\n");
		printf("Please enter a number : ");
	}
	return y;
}

int main()
{
	double x = 0.0, y = 0.0;
	char ch = '\0';

	menu();

	while ((ch = getchar()) != 'q')
	{
		if (ch == 'a')
		{
			x = return_x();
			y = return_y();
			printf("%lf + %lf = %lf\n", x, y, x + y);
			menu();
		}
		else if (ch == 's')
		{
			x = return_x();
			y = return_y();
			printf("%lf - %lf = %lf\n", x, y, x - y);
			menu();
		}
		else if (ch == 'm')
		{
			x = return_x();
			y = return_y();
			printf("%lf * %lf = %f\n", x, y, x * y);
			menu();
		}
		else if (ch == 'd')
		{
			x = return_x();
			y = return_y();
			while (y < 0.0000001 && y > -0.0000001)
			{
				printf("Enter a number other than 0 : ");
				scanf("%lf", &y);
			}
			printf("%lf / %lf = %lf\n", x, y, x / y);
			menu();
		}
		else
			printf("Enter once again : ");
		while (getchar() != '\n')
			continue;
	}

	printf("bye.\n");
	system("pause");
	return 0;
}