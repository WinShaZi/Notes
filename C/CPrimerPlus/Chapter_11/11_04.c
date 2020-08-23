#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

char *get(char *out, char *re, int n)
{
	int i = 0, j = 0;

	fgets(out, SIZE, stdin);
	for (i = 0; i < SIZE; i++)
	{
		if (out[i] == EOF)
			break;
		else if (out[i] <= ' ')
			continue;
		else
		{
			if (j < n)
				re[j] = out[i];
			else
				break;
			if (out[i + 1] <= ' ')
				break;
			j++;
		}
	}
	if (out[i] == EOF)
		return NULL;
	else
	{
		re[j] = '\0';
		return re;
	}
}

int main()
{
	int n;
	char *in;
	char out[SIZE];
	char re[SIZE];

	printf("Input a number : ");
	scanf("%d", &n);
	while (getchar() != '\n')
		continue;
	printf("Input a character string : ");
	in = get(out, re, n);

	if (*in != EOF)
		puts(re);
	else
		puts("Error!\n");

	system("pause");
	return 0;
}