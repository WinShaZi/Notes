#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

int is_within(char *p, char ch)
{
	if (strchr(p, ch))
		return 1;
	return 0;
}

int main()
{
	char ch = '\0';
	char p[SIZE] = "\0";

	printf("Input a character string : ");
	fgets(p, SIZE, stdin);
	printf("Input a character : ");
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
			continue;
		if (is_within(p, ch))
			printf("1\n");
		else
			printf("0\n");
		printf("Input a character : ");
	}

	system("pause");
	return 0;
}