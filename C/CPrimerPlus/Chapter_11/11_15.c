#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 50

double atoi_0(char * st)
{
	int i = 0;
	int n = 0;
	double result = 0;
	n = strlen(st);

	for (i = 0; i < n; i++)
	{
		if (isdigit(st[i]))
		{
			result += (st[i] - '0') * pow(10, (n - i - 1));
		}

		else
			return 0;
	}

	return result;
}

int main()
{
	char st[SIZE] = "\0";
	double num = 0;

	gets_s(st, SIZE);
	num = atoi_0(st);
	printf("%d\n", (int)num);

	system("pause");
	return 0;
}