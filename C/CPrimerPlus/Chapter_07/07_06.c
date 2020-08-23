#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch = '\0', ch_a = 'a';
	int i = 0;

	while ((ch = getchar()) != '#')
	{
		if (ch_a == 'e')
		{
			if (ch == 'i')
				i++;
		}
		ch_a = ch;
	}
	printf("ei is %d.\n", i);

	system("pause");
	return 0;
}