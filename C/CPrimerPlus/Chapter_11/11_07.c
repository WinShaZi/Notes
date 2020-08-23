#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

char *s_gets(char *st, int n)
{
	char *re = NULL;
	int i = 0;

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

char *mystrncpy(char *s1, char *s2)
{
	int i = 0, j = 0, n = 0;
	
	i = strlen(s1);
	j = strlen(s2);
	if ((i + j - 1) <= SIZE)
	{
		for (n = 0; n < j; n++)
			s1[i + n] = s2[n];
		s1[i + n] = '\0';
		return s1;
	}
	else
		return s1;
}

int main()
{
	char s1[SIZE] = "\0", s2[SIZE] = "\0", *ss = NULL;

	printf("Input a character string : ");
	s_gets(s1, SIZE);
	printf("Input another character string : ");
	s_gets(s2, SIZE);
	ss = mystrncpy(s1, s2);
	puts(ss);

	system("pause");
	return 0;
}