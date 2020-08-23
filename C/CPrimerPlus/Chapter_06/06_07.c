#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char ch[40] = "\0";
	int i = 0;

	printf("Input a word : ");
	scanf("%s", ch, 40);
	for (i = strlen(ch) - 1; i >= 0; i--)
		printf("%c", ch[i]);
	printf("\n");

	system("pause");
	return 0;
}