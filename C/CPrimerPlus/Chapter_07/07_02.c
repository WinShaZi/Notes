#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch = '\0';
	int i = 0;

	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
		{
			i = 0;
			putchar('\n');
			continue;
		}
		if ((i % 8) == 0 && i != 0)
			printf("\n");
		i++;
		printf("%-2c%-6d", ch, (int)ch);
	}

	system("pause");
	return 0;
}