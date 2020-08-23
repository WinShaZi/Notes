#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

char *s_gets(char *st, int n)
{
	int i = 0;
	char *re = NULL;

	re = fgets(st, n, stdin);
	if (re)
	{
		while (st[i] != '\n'&&st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return re;
}

char *string_in(char *s1, char *s2)
{
	int i = 0, m = 0, n = 0;

	m = strlen(s1);
	n = strlen(s2);
	for (i = 0; i < m; i++)
	{
		if (strncmp(s1 + i, s2, n) == 0)
			return s1 + i;
	}

	return NULL;
}

int main()
{
	char s1[SIZE] = "\0";
	char s2[SIZE] = "\0";
	char *ss = NULL;

	printf("Input a charachar string : ");
	s_gets(s1, SIZE);
	printf("Input another characahr string : ");
	s_gets(s2, SIZE);
	while (s2[0] != '#')
	{
		ss = string_in(s1, s2);
		if (ss)
			printf("s1[%d]\n", ss - s1);
		else
			puts("None.");
		printf("Input a characahr string : ");
		s_gets(s2, SIZE);
	}
	puts("Done.");

	system("pause");
	return 0;
}