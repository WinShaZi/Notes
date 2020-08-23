#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 20

struct all
{
	char name[SIZE];
	char na[SIZE];
	int day;
	int month;
};

struct all months[12] =
{
	{ "January", "jan", 31, 1 },
	{ "February", "feb", 28, 2 },
	{ "March", "mar", 31, 3 },
	{ "April", "apr", 30, 4 },
	{ "May", "may", 31, 5 },
	{ "Juny", "jun", 30, 6 },
	{ "July", "jul", 31, 7},
	{ "August", "aug", 31, 8 },
	{ "September", "sep", 30, 9},
	{ "October", "oct", 31, 10},
	{ "November", "nov", 30, 11},
	{ "December", "dec", 31, 12},
};

char *s_gets(char *st, int n)
{
	char *ret_val = NULL;
	char *find = NULL;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

int m_max(char *m_n, int m)
{
	if (m == 0)
	{
		for (int i = 0; i < 12; i++)
			if (strcmp(m_n, months[i].name) == 0 || strcmp(m_n, months[i].na))
				return (months[i].day);
		return 1;
	}
	else
		return (months[m - 1].day);
}

int all(char * m_n, int m, int d)
{
	int i = 0;
	int num = 0;
	int count = 0;
	int total = 0;

	num = strlen(m_n);
	if (m == 0)
	{
		if (num > 3)
			m_n[0] = toupper(m_n[0]);

		for (i = 1; i < num; i++)
			m_n[i] = tolower(m_n[i]);
		for (i = 0; i < 12; i++)
			if (strcmp(m_n, months[i].name) == 0 || strcmp(m_n, months[i].na))
			{
				count = months[i].month;
				break;
			}
		if (count == 0)
			return -1;
		else
			for (i = 0; i < count; i++)
				total += months[i].day;
	}
	else
		for (i = 0; i < m - 1; i++)
			total += months[i].day;

	return (total + d);
}

int main()
{
	char month_name[SIZE] = "NO";
	int total = 0;
	int year = 0;
	int month = 0;
	int day = 0;
	bool jump = true;

	printf("Input year : ");
	while (scanf("%d", &year) && year >= 0)
	{
		if (year % 4 == 0)
			months[1].day = 29;
		while (getchar() != '\n')
			continue;

		printf("Input moonth : ");
		if (scanf("%d", &month))
		{
			printf("Input days : ");
			if (scanf("%d", &day) && day > 0 && day <= m_max(month_name, month))
			{
				total = all(month_name, month, day);
				printf("Until %d years %d months %d days : %d\n", year, month, day, total);
			}
			else
			{
				jump = false;
				printf("Error!\n");
			}
		}
		else if ((s_gets(month_name, SIZE) != NULL && month_name[0] != '\0'))
		{
			printf("Input days : ");
			if (scanf("%d", &day) && day > 0 && day <= m_max(month_name, month))
			{
				total = all(month_name, month, day);

				if (total == -1)
					printf("%s is not month.\n", month_name);
				else
				{
					if (month == 0)
						printf("Until %d years %s months %d days : %d\n", year, month_name, day, total);
					else
						printf("Until %d years %d months %d days : %d\n", year, month, day, total);
				}
			}
			else
			{
				jump = false;
				printf("Error!\n");
			}
		}
		else
		{
			jump = false;
			printf("Error!\n");
		}
		if (jump)
			printf("Next year input : ");
	}
	printf("Bye!\n");

	system("pause");
	return 0;
}