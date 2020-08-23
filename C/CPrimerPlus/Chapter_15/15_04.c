#include <stdio.h>
#include <stdlib.h>

#define SIZE sizeof(int) * 8

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

int open(char *st, int i)
{
	if (st[SIZE - i - 1] == '1')
		return 1;
	else
		return 0;
}

int main()
{
	int n = 0, i = 0;

	printf("Input tow integers : ");
	while (scanf("%d%d", &n, &i) == 2)
	{
		while (getchar() != '\n')
			continue;
		if (i < 0 || i > 31)
			continue;

		char st[SIZE + 1];
		char sr[SIZE + 8];

		printf("%s\n", itobs(st, sr, n));

		int mode = open(st, i);

		if (mode == 1)
			printf("%d bit is open.\n", i);
		else
			printf("%d bit is close.\n", i);
		printf("Next input : ");
	}
	puts("Done.");

	system("Pause");
	return 0;
}