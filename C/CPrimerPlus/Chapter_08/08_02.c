#include <stdio.h>
#include <stdlib.h>

#define NUM 10

int main()
{
	char ch = '\0';
	int i = 0;

	while ((ch = getchar()) != EOF)
	{
		i++;
		if (ch < ' ')
		{
			if (ch == '\n')
			{
				putchar('\\');
				printf("n %d  ", (int)ch);
				i = 0;
			}
			else if (ch == '\t')
			{
				putchar('\\');
				printf("t %d  ", (int)ch);
			}
			else
				printf("^%c  ", ch + 64);
		}
		else
			printf("%c %d  ", ch, (int)ch);
		if (i % NUM == 0)
			putchar('\n');
	}

	system("pause");
	return 0;
}