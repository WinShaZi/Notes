#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
	char ch = '\0';
	int i = 0, j = 0;
	bool word = false;

	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
			i++;
		if (isalpha(ch) && !word)
		{
			word = true;
			j++;
		}
		if (!isalpha(ch) && word)
			word = false;
	}
	printf("The average %d word has %f letter.\n", j, (float)i / j);

	system("pause");
	return 0;
}