#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int letter(char ch)
{
	if (islower(ch))
		return (int)ch - 96;
	else if (isupper(ch))
		return (int)ch - 64;
	else
		return -1;
}

int main()
{
	char ch = 0;
	int num = 0;

	printf("Input a string of characters : ");
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
			continue;
		num = letter(ch);
		if (num == -1)
			printf("%c is not letter.\n", ch);
		else
			printf("%c is %d\n", ch, num);
	}

	system("pause");
	return 0;
}