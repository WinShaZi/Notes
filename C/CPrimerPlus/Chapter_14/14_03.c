#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 
#define TITLE "TITLE"
#define AUTHOR "AUTHOR"
#define VALUE "VALUE"

struct book 
{ 
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

void _title(struct book *pt[], int count)
{
	int i = 0, j = 0;
	struct book * temp = NULL;

	for (i = 0; i < count - 1; i++)
		for (j = i + 1; j < count; j++)
			if (strcmp(pt[i]->title, pt[j]->title) > 0)
			{
				temp = pt[j];
				pt[j] = pt[i];
				pt[i] = temp;
			}
}

void _value(struct book *pt[], int count)
{
	int i = 0, j = 0;
	struct book * temp = NULL;

	for (i = 0; i < count - 1; i++)
		for (j = i + 1; j < count; j++)
			if (pt[i]->value > pt[j]->value)
			{
				temp = pt[j];
				pt[j] = pt[i];
				pt[i] = temp;
			}
}

char *s_gets(char * st, int n)
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

int main()
{
	struct book library[MAXBKS];
	struct book *pt[MAXBKS] = NULL;
	int count = 0;
	int index = 0;

	printf("Input the book title : ");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		printf("Input the author : ");
		s_gets(library[count].author, MAXAUTL);
		printf("Input the value : ");
		scanf("%f", &library[count].value);
		pt[count] = &library[count];
		count++;
		while (getchar() != '\n')
			continue;
		system("CLS");
		if (count < MAXBKS)
		{
			printf("There are alreay %d book(s) here.\n", count);
			printf("Input the next title : ");
		}
	}
	system("CLS");

	if (count > 0)
	{
		printf("%-20s %-20s %s\n", TITLE, AUTHOR, VALUE);
		printf("\nHere is the list of your books :\n");
		for (index = 0; index < count; index++)
			printf("%-20s %-20s $%.2f\n", library[index].title, library[index].author, library[index].value);

		printf("\nBook title :\n");
		_title(pt, count);
		for (index = 0; index < count; index++)
			printf("%-20s %-20s $%.2f\n", pt[index]->title, pt[index]->author, pt[index]->value);

		_value(pt, count);
		printf("\nBook value :\n");
		for (index = 0; index < count; index++)
			printf("%-20s %-20s $%.2f\n", pt[index]->title, pt[index]->author, pt[index]->value);
	}
	else
		printf("No book !\n");

	system("pause");
	return 0;
}