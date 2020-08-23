#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

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

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main()
{
	struct book library[MAXBKS] =
	{
		{ "", "", 0.0 },
		{ "", "", 0.0 },
		{ "", "", 0.0 },
		{ "", "", 0.0 },
		{ "", "", 0.0 },
		{ "", "", 0.0 },
		{ "", "", 0.0 },
		{ "", "", 0.0 },
		{ "", "", 0.0 },
		{ "", "", 0.0 }
	};
	struct book detale = { "***","***",0.0 };
	FILE *pbooks = NULL;
	int i = 0;
	int num = 0;
	int size = sizeof(struct book);
	char choose = 0;
	bool mode = true;

	fopen_s(&pbooks, "book.dat", "r+b");
	if (pbooks == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}

	rewind(pbooks);
	printf("Here is your book library :\n");
	while (1)
	{
		fscanf_s(pbooks, "%s %s %f", library[i].title, MAXTITL, library[i].author, MAXAUTL, &library[i].value);
		if (library[i].title[0] == '\0')
		{
			if (library[0].title[0] == '\0')
				mode = false;
			break;
		}
		printf("%d. %s %s %.2f\n", i + 1, library[i].title, library[i].author, library[i].value);
		i++;
	}

	if (mode)
	{
		printf("Which book do you want to change : ");
		while (scanf("%d", &num) == 1)
		{
			while (getchar() != '\n')
				continue;
			if (num <= i && num >= 1)
			{
				printf("Change or Delete(c/d) : ");
				scanf("%c", &choose, 1);
				choose = tolower(choose);
				while (getchar() != '\n')
					continue;
				if (choose == 'd')
					library[num - 1] = detale;
				else if (choose == 'c')
				{
					printf("Input title : ");
					s_gets(library[num - 1].title, MAXTITL);
					printf("Input author : ");
					s_gets(library[num - 1].author, MAXAUTL);
					printf("Input value : ");
					scanf("%f", &library[num - 1].value);
				}
				fclose(pbooks);

				fopen_s(&pbooks, "book.dat", "w");
				for (int j = 0; j < i; j++)
				{
					fprintf(pbooks, "%s %s %.2f\n", library[j].title, library[j].author, library[j].value);
					printf("%d. %s %s %.2f\n", j + 1, library[j].title, library[j].author, library[j].value);
				}
			}
			else
				printf("No book.\n");
			printf("Which book do you want to change : ");
		}
	}
	else
	{
		system("CLS");
		printf("No book.\n");
	}

	fclose(pbooks);

	system("pause");
	return 0;
}