#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50
#define NUM 10

void menu()
{
	printf("********************************************************************\n");
	printf("* Input 10 character string                                        *\n");
	printf("* 1) Print source character     2) Ranking by ASCII                *\n");
	printf("* 3) Ranking by length          4) Ranking by first letter length  *\n");
	printf("* 5) Quit                                                          *\n");
	printf("********************************************************************\n");
}

char  *s_gets(char *st)
{
	int i = 0;
	char *re = NULL;

	re = fgets(st, SIZE, stdin);
	if (re)
	{
		while (st[i] != '\0'&&st[i] != '\n')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
	}

	return re;
}

int first_word(char *p)
{
	int i = 0;

	for (; !isalpha(*p); p++)
		if (*p == '\0')
			return 0;
	for (i = 1; isalpha(p[i]); i++)
		continue;

	return i;
}


fx_1(char **p)
{
	int n = 0;

	for (n = 0; n < NUM; n++)
		puts(p[n]);
}

fx_2(char **p)
{
	int i = 0, j = 0;
	char *temp = NULL;

	for (i = 0; i < NUM; i++)
		for (j = 0; j < NUM - i - 1; j++)
			if (strcmp(p[j], p[j + 1]) > 0)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
	fx_1(p);
}

fx_3(char **p)
{
	int i = 0, j = 0;
	char *temp = NULL;

	for (i = 0; i < NUM; i++)
		for (j = 0; j < NUM - i - 1; j++)
			if (strlen(p[j]) > strlen(p[j + 1]))
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
	fx_1(p);
}

fx_4(char **p)
{
	int i = 0, j = 0;
	char *temp = NULL;

	for (i = 0; i < NUM; i++)
		for (j = 0; j < NUM - i - 1; j++)
			if (first_word(p[j]) > first_word(p[j + 1]))
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
	fx_1(p);
}

int main()
{
	char st[NUM][SIZE] = {'\0'};
	char *p[NUM] = {'\0'};
	int n = 0, num = 1;
	int choose = 0;

	menu();
	for (n = 0; n < NUM; n++)
	{
		printf("Character string ( %d ) : ", num++);
		if (s_gets(st[n]))
			p[n] = st[n];
	}
	printf("Input you choose : ");
	while (scanf("%d", &choose) == 1)
	{
		switch (choose)
		{
		case 1:
			fx_1(p);
			break;
		case 2:
			fx_2(p);
			break;
		case 3:
			fx_3(p);
			break;
		case 4:
			fx_4(p);
			break;
		case 5:
			break;
		default:
			printf("Input you choose : ");
		}
		if (choose == 5)
			break;
		menu();
	}
	puts("Done!");

	system("pause");
	return 0;
}