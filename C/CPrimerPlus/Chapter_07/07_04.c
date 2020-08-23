#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch = '\0';
	int i = 0, j = 0;

	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case '.':
			putchar('!');
			i++;
			continue;
		case '!':
			putchar('!');
			putchar('!');
			j++;
			continue;
		default:
			putchar(ch);
		}
	}
	printf("\n. is %d.\n! is %d.\n", i, j);

	system("pause");
	return 0;
}