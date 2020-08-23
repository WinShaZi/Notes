#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

char *get(char *out, char *re)
{
	int i = 0, j = 0;

	fgets(out, SIZE, stdin);
	re[0] = '\0';
	if (out[0] == '\n')
		return NULL;
	for (i = 0, j = 0; i < SIZE; i++)
	{
		if (out[i] <= ' ')
		{
			if (j == 0)
				continue;
			break;
		}
		re[j] = out[i];
		re[++j] = '\0';
	}

	return re;
}

int main()
{
	char out[SIZE] = "\0";
	char re[SIZE] = "\0";

	if (get(out, re) != NULL && re[0] != '\0')
		puts(re);
	else
		puts("Error!");

	system("pause");
	return 0;
}