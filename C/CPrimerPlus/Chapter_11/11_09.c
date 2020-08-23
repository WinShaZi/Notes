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

char change(char *ch, char *temp)
{
	int i = 0, n = 0;

	n = strlen(ch);
	for (i = 0; i < n; i++)
		temp[i] = ch[n - 1 - i];
	for (i = 0; i < n; i++)
		ch[i] = temp[i];

	return *ch;
}

int main()
{
	char ch[SIZE] = "\0";
	char temp[SIZE] = "\0";

	printf("Input a character string : ");
	ch[0] = '\0';
	while (s_gets(ch, SIZE) && ch[0] != '#')
	{
		change(ch, temp);
		puts(ch);
		printf("Input a character string : ");
	}
	puts("Done.");

	system("pause");
	return 0;
}