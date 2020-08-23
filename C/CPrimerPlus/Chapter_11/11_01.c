#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

char *get(char *pp, int n)
{
	int i = 0;
	char ch = '\0';

	for (i = 0; i < n - 1; i++)
	{
		ch = getchar();
		if (ch == EOF)
			break;
		pp[i] = ch;
		pp[i + 1] = '\0';
	}
	if (ch == EOF)
		return NULL;

	return pp;
}

int main()
{
	char out[SIZE] = "\0";

	if (get(out, SIZE) == NULL)
		puts("Error!");
	else
		puts(out);

	system("pause");
	return 0;
}