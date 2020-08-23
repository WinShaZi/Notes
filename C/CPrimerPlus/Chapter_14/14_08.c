#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 20
#define SIZE 12

struct message
{
	int num;
	int mode;
	char first[LEN];
	char last[LEN];
};

void clean()
{
	while (getchar() != '\n')
		continue;
}

char  menu()
{
	char ch = '\0';

	printf("To choose a function, enter its letter label :\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n");
	printf("Input you choose(# to quit) : ");
	scanf("%c", &ch, 1);
	if (ch == '#')
		ch = 'f';
	ch = tolower(ch);
	clean();

	return ch;
}

void _full(struct message flight[])
{
	printf("Full seat : ");
	for (int i = 0; i < SIZE; i++)
		if (flight[i].mode == 1)
			printf("%d ", flight[i].num);
	putchar('\n');
}

void _a(struct message flight[])
{
	printf("Empty seat : ");
	for (int i = 0; i < SIZE; i++)
		if (flight[i].mode == 0)
			printf("%-2d ", flight[i].num);
	putchar('\n');
}

void _b(struct message flight[])
{
	for (int i = 0; i < SIZE; i++)
		if (flight[i].mode == 0)
			printf("%2d\n", flight[i].num);
}

void _c(struct message flight[])
{
	struct message temp;

	for (int i = 0; i < SIZE - 1; i++)
		for (int j = i + 1; j < SIZE; j++)
		{
			if (strcmp(flight[i].first, flight[j].first) > 0)
			{
				temp = flight[i];
				flight[i] = flight[j];
				flight[j] = temp;
			}
			else if (strcmp(flight[i].first, flight[j].first) == 0 && strcmp(flight[i].last, flight[j].last) > 0)
			{
				temp = flight[i];
				flight[i] = flight[j];
				flight[j] = temp;
			}
		}

	for (int i = 0; i < SIZE; i++)
		if (flight[i].mode == 1)
			printf("%2d %20s %20s\n", i + 1, flight[i].first, flight[i].last);
}

void _d(struct message flight[])
{
	int n = 0;

	_a(flight);
	printf("Input seat number : ");
	while (scanf("%d", &n) == 1)
	{
		clean();
		if (n < 1 || n > SIZE)
		{
			printf("No %d seat.\n", n);
			printf("Input seat number : ");
			continue;
		}
		if (flight[n - 1].mode == 1)
		{
			printf("The seat is full.\n");
			printf("Input seat number : ");
			continue;
		}
		printf("Input your first name : ");
		scanf("%s", flight[n - 1].first, LEN);
		clean();
		printf("Input your last name : ");
		scanf("%s", flight[n - 1].last, LEN);
		clean();
		flight[n - 1].mode = 1;
		printf("Order successful\n");
		printf("Next number(# to quit) : ");
	}
	clean();
}

void _e(struct message flight[])
{
	int n = 0;

	_full(flight);
	printf("Input seat number : ");
	while (scanf("%d", &n) == 1)
	{
		clean();
		if (n < 1 || n > SIZE)
		{
			printf("No %d seat.\n", n);
			printf("Input seat number : ");
			continue;
		}
		if (flight[n - 1].mode == 0)
		{
			printf("The seat is empty.\n");
			printf("Input seat number : ");
			continue;
		}
		flight[n - 1].first[0] = '\0';
		flight[n - 1].last[0] = '\0';
		flight[n - 1].mode = 0;
		printf("Delete successful\n");
		printf("Next number(# to quit) : ");
	}
	clean();
}

int main()
{
	struct message flight[SIZE] =
	{
		{ 1, 1, "AAA", "aaa" },
		{ 2, 0, "", "" },
		{ 3, 1, "BBB", "bbb" },
		{ 4, 0, "", "" },
		{ 5, 0, "", "" },
		{ 6, 0, "", "" },
		{ 7, 1, "CCC", "ccc" },
		{ 8, 0, "", "" },
		{ 9, 0, "", "" },
		{ 10, 0, "", "" },
		{ 11, 1, "DDD", "ddd" },
		{ 12, 1, "EEE", "eee" }
	};
	char ch = '\0';

	ch = menu();
	while (ch <= 'f' && ch >= 'a')
	{
		switch (ch)
		{
		case 'a':
			_a(flight);
			break;
		case 'b':
			_b(flight);
			break;
		case 'c':
			_c(flight);
			break;
		case 'd':
			_d(flight);
			break;
		case 'e':
			_e(flight);
			break;
		case 'f':
			break;
		}
		if (ch == 'f')
			break;
		putchar('\n');
		ch = menu();
	}
	printf("Done.\n");

	system("pause");
	return 0;
}