#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char word[255] = "\0";
	int i = 0;

	printf("Input a line symbol : ");
	scanf("%s", word, 255);
	for (i = strlen(word) - 1; i >= 0; i--)
		printf("%c", word[i]);
	printf("\n");

	system("pause");
	return 0;
}