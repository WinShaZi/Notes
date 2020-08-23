#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 20
#define SIZE 48
#define SI 12

int number = 0;
char ch = '\0';

struct message
{
	int num;
	int seat;
	int mode;
	char first[LEN];
	char last[LEN];
};

struct message num_seat[SI];
struct message all_seat[SIZE] =
{
	{ 102, 1, 1, "AAA", "aaa" },
	{ 102, 2, 0, "", "" },
	{ 102, 3, 1, "BBB", "bbb" },
	{ 102, 4, 0, "", "" },
	{ 102, 5, 0, "", "" },
	{ 102, 6, 0, "", "" },
	{ 102, 7, 1, "CCC", "ccc" },
	{ 102, 8, 0, "", "" },
	{ 102, 9, 0, "", "" },
	{ 102, 10, 0, "", "" },
	{ 102, 11, 1, "DDD", "ddd" },
	{ 102, 12, 1, "EEE", "eee" },
	{ 311, 1, 1, "AAA", "aaa" },
	{ 311, 2, 0, "", "" },
	{ 311, 3, 1, "FFF", "fff" },
	{ 311, 4, 0, "", "" },
	{ 311, 5, 0, "", "" },
	{ 311, 6, 0, "", "" },
	{ 311, 7, 1, "CCC", "ccc" },
	{ 311, 8, 0, "", "" },
	{ 311, 9, 0, "", "" },
	{ 311, 10, 0, "", "" },
	{ 311, 11, 1, "DDD", "ddd" },
	{ 311, 12, 1, "EEE", "eee" },
	{ 444, 1, 1, "AAA", "aaa" },
	{ 444, 2, 0, "", "" },
	{ 444, 3, 1, "BBB", "bbb" },
	{ 444, 4, 0, "", "" },
	{ 444, 5, 0, "", "" },
	{ 444, 6, 0, "", "" },
	{ 444, 7, 1, "CCC", "ccc" },
	{ 444, 8, 0, "", "" },
	{ 444, 9, 1, "RRR", "rrr" },
	{ 444, 10, 0, "", "" },
	{ 444, 11, 1, "DDD", "ddd" },
	{ 444, 12, 0, "", "" },
	{ 519, 1, 0, "", "" },
	{ 519, 2, 0, "", "" },
	{ 519, 3, 1, "BBB", "bbb" },
	{ 519, 4, 0, "", "" },
	{ 519, 5, 1, "KKK", "kkk" },
	{ 519, 6, 0, "", "" },
	{ 519, 7, 1, "CCC", "ccc" },
	{ 519, 8, 0, "", "" },
	{ 519, 9, 0, "", "" },
	{ 519, 10, 0, "", "" },
	{ 519, 11, 1, "DDD", "ddd" },
	{ 519, 12, 1, "EEE", "eee" }
};

void _clean();
void _flight();
void _menu();
void _seat();
void _sync();
void _choose();
void _full();
void _a();
void _b();
void _c();
void _d();
void _e();

int main()
{
	_flight();
	_choose();

	puts("Done.");

	system("pause");
	return 0;
}

void _clean()
{
	while (getchar() != '\n');
}

void _flight()
{
	printf("102 311 444 519\n");
	printf("Choose flight : ");
	scanf("%d", &number);
	_clean();
	while (number != 0 && number != 102 && number != 311 && number != 444 && number != 519)
	{
		printf("Choose flight : ");
		if (!scanf("%d", &number))
			number = 0;
		_clean();
	}
	if (number != 0)
		_menu();
}

void _menu()
{
	printf("To choose a function, enter its letter label :\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n");
	printf("Input you choose (# to quit): ");
	scanf("%c", &ch, 1);
	ch = tolower(ch);
	_clean();
	if (ch >= 'a'&&ch <'f')
		_seat();
}

void _seat()
{
	for (int i = 0, j = 0; j < SI; i++)
		if (all_seat[i].num == number)
		{
			num_seat[j] = all_seat[i];
			j++;
		}
}

void _sync()
{
	for (int i = 0, j = 0; j < SI; i++)
		if (all_seat[i].num == number)
		{
			all_seat[i] = num_seat[j];
			j++;
		}
}

void _choose()
{
	while (number != 0)
	{
		switch (ch)
		{
		case 'a':
			_a();
			putchar('\n');
			_menu();
			continue;
		case 'b':
			_b();
			putchar('\n');
			_menu();
			continue;
		case 'c':
			_c();
			putchar('\n');
			_menu();
			continue;
		case 'd':
			_d();
			putchar('\n');
			_menu();
			continue;
		case 'e':
			_e();
			putchar('\n');
			_menu();
			continue;
		case 'f':
			number = 0;
			break;
		default:
			putchar('\n');
			_menu();
			continue;
		}
		putchar('\n');
		_flight();
	}
}

void _full()
{
	printf("Full seat : ");
	for (int i = 0; i < SI; i++)
		if (num_seat[i].mode == 1)
			printf("%d ", num_seat[i].seat);
	putchar('\n');
}

void _a()
{
	printf("Empty seat : ");
	for (int i = 0; i < SI; i++)
		if (num_seat[i].mode == 0)
			printf("%-2d ", num_seat[i].seat);
	putchar('\n');
}

void _b()
{
	for (int i = 0; i < SI; i++)
		if (num_seat[i].mode == 0)
			printf("%2d\n", num_seat[i].seat);
}

void _c()
{
	struct message temp;

	for (int i = 0; i < SI - 1; i++)
		for (int j = i + 1; j < SI; j++)
		{
			if (strcmp(num_seat[i].first, num_seat[j].first) > 0)
			{
				temp = num_seat[i];
				num_seat[i] = num_seat[j];
				num_seat[j] = temp;
			}
			else if (strcmp(num_seat[i].first, num_seat[j].first) == 0 && strcmp(num_seat[i].last, num_seat[j].last) > 0)
			{
				temp = num_seat[i];
				num_seat[i] = num_seat[j];
				num_seat[j] = temp;
			}
		}

	for (int i = 0; i < SI; i++)
		if (num_seat[i].mode == 1)
			printf("%2d %20s %20s\n", num_seat[i].seat, num_seat[i].first, num_seat[i].last);
}

void _d()
{
	int n = 0;

	_a();
	printf("Input seat number : ");
	while (scanf("%d", &n) == 1)
	{
		_clean();
		if (n < 1 || n > SI)
		{
			printf("No %d seat.\n", n);
			printf("Input seat number : ");
			continue;
		}
		if (num_seat[n - 1].mode == 1)
		{
			printf("The seat is full.\n");
			printf("Input seat number : ");
			continue;
		}
		printf("Input your first name : ");
		scanf("%s", num_seat[n - 1].first, LEN);
		_clean();
		printf("Input your last name : ");
		scanf("%s", num_seat[n - 1].last, LEN);
		_clean();
		num_seat[n - 1].mode = 1;
		_sync();
		printf("Order successful\n");
		_a();
		printf("Next number(# to quit) : ");
	}
	_clean();
}

void _e()
{
	int n = 0;

	_full();
	printf("Input seat number : ");
	while (scanf("%d", &n) == 1)
	{
		_clean();
		if (n < 1 || n > SI)
		{
			printf("No %d seat.\n", n);
			printf("Input seat number : ");
			continue;
		}
		if (num_seat[n - 1].mode == 0)
		{
			printf("The seat is empty.\n");
			printf("Input seat number : ");
			continue;
		}
		num_seat[n - 1].first[0] = '\0';
		num_seat[n - 1].last[0] = '\0';
		num_seat[n - 1].mode = 0;
		_sync();
		printf("Delete successful\n");
		_full();
		printf("Next number(# to quit) : ");
	}
	_clean();
}