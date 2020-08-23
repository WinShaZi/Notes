#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

char *find(char *input, char need, char *re)
{
	int i = 0, n = 0;
	n = strlen(input);

	for (i = 0; i < n; i++)
	{
		if (need == input[i])
		{
			re = &input[i];
			return re;
		}
	}

	return NULL;
}
int main()
{
	char input[SIZE] = "\0";
	char need = '\0';
	char re[SIZE] = "\0";

	printf("Input a character string : ");
	fgets(input, SIZE, stdin);
	printf("Input you want the character : ");
	scanf("%c", &need, SIZE);
	find(input, need, re);
	if (find(input, need, re) != NULL)
		printf("input[%d]\n", find(input, need, re) - input);
	else
		puts("None!");

	system("pause");
	return 0;
}