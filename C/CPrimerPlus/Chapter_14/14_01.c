#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20

struct year
{
	char name[SIZE];
	char na[SIZE];
	int day;
	int month;
};

const struct year months[12] =
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

int all(char * mon_name)
{
	int i = 0;
	int num = 0;
	int count = 0;
	int total = 0;

	mon_name[0] = toupper(mon_name[0]);
	num = strlen(mon_name);
	for (i = 1; i < num; i++)
		mon_name[i] = tolower(mon_name[i]);
	for (i = 0; i < 12; i++)
		if (strcmp(mon_name, months[i].name) == 0)
		{
			count = months[i].month;
			break;
		}
	if (count == 0)
		return -1;
	else
	{
		for (i = 0; i < count; i++)
			total += months[i].day;
		return total;
	}
}


int main()
{
	char mon_name[SIZE] = "\0";
	int total = 0;

	printf("Input moonth : ");
	while (s_gets(mon_name, SIZE) != NULL && mon_name[0] != '\0')
	{
		total = all(mon_name);
		if (total == -1)
			printf("%s is not month.\n", mon_name);
		else
			printf("Until %s : %d\n", mon_name, total);
		printf("Next input : ");
	}
	printf("Bye!\n");

	system("pause");
	return 0;
}