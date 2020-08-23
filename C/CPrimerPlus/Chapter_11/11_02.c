#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define INPUT "Input a number : "

char *get(char *pp, int num)
{
	int i = 0;
	char ch = '\0';

	for (i = 0; i < num; i++)
	{
		ch = getchar();
		if (ch <= ' ')
			break;
		pp[i] = ch;
	}
	if (ch == EOF)
		return NULL;
	else
		pp[i] = '\0';

	return pp;
}

int main()
{
	char out[SIZE] = "\0";
	int num = 0;

	printf(INPUT);
	while (scanf("%d", &num) != 1 || num > SIZE - 1 || num < 0)
		printf(INPUT);

	while (getchar() != '\n')
		continue;

	printf("Input a character string : ");

	if (get(out, num) == NULL)
		puts("Error!");
	else
		puts(out);

	system("pause");
	return 0;
}