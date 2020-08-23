#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 255

char *s_gets(char *st, int n)
{
	char *ret_val = NULL;
	char *find = NULL;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

int number(char *pbin, int n)
{
	double num = 0;

	for (int i = 0, j = 0; i < n; i++)
		if (pbin[n - i - 1] != ' ')
			num += (pbin[n - i - 1] - '0') * pow(2, j++);

	return (int)num;
}

int main()
{
	char pbin[SIZE] = "\0";
	int len = 0;
	bool mode = true;

	printf("Input : ");
	while (s_gets(pbin, SIZE) && pbin[0] != '\0')
	{
		mode = true;
		len = strlen(pbin);
		for (int i = 0; i < len; i++)
			if (pbin[i] != '0' && pbin[i] != '1'&& pbin[i] != ' ')
			{
				printf("Input error.\n");
				mode = false;
				break;
			}
		if (mode)
			printf("%s = %d\n", pbin, number(pbin, len));
		printf("Input : ");
	}

	system("pause");
	return 0;
}