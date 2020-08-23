#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 255

int main()
{
	char st[SIZE][SIZE] = {'\0'};
	char ch = '\0';
	int in = 0, word = 0;
	int i = 0, j = 0;

	while ((ch = getchar()) != EOF)
	{
		if (!isalpha(ch) && !in)
		{
			in = 1;
			word++;
		}
		if (isalpha(ch) && in)
			in = 0;

		if (isalpha(ch) && !in)
		{
			st[i][j] = ch;
			j++;
		}
		if (!isalpha(ch) && in)
		{
			st[i][j] = '\0';
			i++;
			j = 0;
		}
	}

	for (; word > 0; word--)
		printf("%s ", st[word - 1]);
	puts("");

	system("pause");
	return 0;
}