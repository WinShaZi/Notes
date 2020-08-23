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

void space(char *ch, int n)
{
	char *p = NULL;
	while (*ch)
	{
		if (*ch == ' ')
		{
			p = ch;
			while (*p)
			{
				*p = *(p + 1);
				p++;
			}
		}
		else
			ch++;
	}
}

int main()
{
	char ch[SIZE] = "\0";

	printf("Input a character string : ");
	while (s_gets(ch, SIZE) && ch[0] != '\0')
	{
		space(ch, SIZE);
		puts(ch);
		printf("Input a character string : ");
	}

	system("pause");
	return 0;
}