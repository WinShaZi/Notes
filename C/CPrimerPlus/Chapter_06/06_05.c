#include <stdio.h>
#include <stdlib.h>

int main()
{
	int right = 0, left = 0, space = 0, line = 0;
	char letter = 0;

	printf("Input a letter : ");
	scanf("%c", &letter, 1);

	for (line = 1; line <= (letter - '@'); line++)
	{
		for (space = (letter - '@') - line; space > 0; space--)
			printf(" ");

		for (left = 0; left < line; left++)
			printf("%c", 'A' + left);

		for (right = line - 1; right > 0; right--)
			printf("%c", '@' + right);

		printf("\n");
	}

	system("pause");
	return 0;
}