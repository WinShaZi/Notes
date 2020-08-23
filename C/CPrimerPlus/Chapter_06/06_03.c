#include <stdio.h>
#include <stdlib.h>

int main()
{
	int letter = 0;
	char ch = 0;

	for (letter = 5; letter >= 0; letter--)
	{
		for (ch = 'F'; ch >= ('A' + letter); ch--)
			printf("%c", ch);
		printf("\n");
	}

	system("pause");
	return 0;
}