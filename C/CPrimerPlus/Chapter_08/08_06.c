#include <stdio.h>
#include <stdlib.h>

char get_first()
{
	char ch = '\0';

	while ((ch = getchar()) <= ' ')
		continue;

	return ch;
}

int main()
{
	char ch = '\0';

	ch = get_first();
	putchar(ch);
	putchar('\n');

	system("pause");
	return 0;
}