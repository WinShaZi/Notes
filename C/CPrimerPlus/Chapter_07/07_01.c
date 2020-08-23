#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch = '\0';
	int space = 0;
	int enter = 0;
	int chara = 0;

	while ((ch = getchar()) != '#')
	{
		if (ch == ' ')
			space++;
		else if (ch == '\n')
			enter++;
		else
			chara++;
	}
	printf("Enter %d\nSpace %d\nOther %d\n", space, enter, chara);

	system("pause");
	return 0;
}