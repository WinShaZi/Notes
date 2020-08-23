#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0, high = 100, low = 1;
	char ch = '\0';

	i = (high + low) / 2;
	printf("%d\n", i);
	printf("h or l or y ?\n");
	while ((ch = getchar()) != 'y')
	{
		if (ch == '\n')
			continue;
		if (ch != 'h' && ch != 'l')
		{
			printf("h or l or y ?\n");
			continue;
		}
		if (ch == 'h')
			high = i - 1;
		else if (ch == 'l')
			low = i + 1;
		i = (high + low) / 2;
		printf("Is it %d ?\n", i);
		printf("h or l or y ?\n");
	}
	printf("I am win !\n");

	system("pause");
	return 0;
}