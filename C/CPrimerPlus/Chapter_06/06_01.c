#include <stdio.h>
#include <stdlib.h>

#define SIZE 26

int main()
{
	int i = 0;
	char letter[SIZE] = "\0";

	for (i = 0; i < SIZE; i++)
		letter[i] = 'a' + i;
	for (i = 0; i < SIZE; i++)
		printf("%c", letter[i]);
	printf("\n");

	system("pause");
	return 0;
}