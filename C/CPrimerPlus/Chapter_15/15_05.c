#include <stdio.h>
#include <stdlib.h>

#define SIZE sizeof(unsigned int) * 8

char *itobs(char *st, char *sr, int n)
{
	int i = 0, j = 0;

	for (i = SIZE - 1; i >= 0; i--, n >>= 1)
		st[i] = (01 & n) + '0';
	st[SIZE] = '\0';

	for (i = 0, j = 0; i < SIZE; i++, j++)
	{
		if (i % 4 == 0 && i != 0)
			sr[j++] = ' ';
		sr[j] = st[i];
	}
	sr[SIZE + 7] = '\0';

	return sr;
}

int rotate_l(char *st, int n, int i)
{
	for (int j = 0; j < i; j++)
	{
		n <<= 1;
		if (st[j] == '1')
			n += 1;
	}

	return n;
}

int main()
{
	unsigned int n = 0, i = 0;

	printf("Input two integers : ");
	while (scanf("%u%u", &n, &i) == 2)
	{
		while (getchar() != '\n')
			continue;

		char st[SIZE];
		char sr[SIZE];

		puts(itobs(st, sr, n));
		puts(itobs(st, sr, rotate_l(st, n, i)));

		printf("Next input : ");
	}

	system("pause");
	return 0;
}