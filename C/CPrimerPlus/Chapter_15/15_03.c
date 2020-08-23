#include <stdio.h>
#include <stdlib.h>

#define BIT 8
#define LEN 255

char *itobs(char *st, char *sr, int n)
{
	int i = 0, j = 0;
	static int size = BIT * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		st[i] = (01 & n) + '0';
	st[size] = '\0';

	for (i = 0, j = 0; i < size; i++, j++)
	{
		if (i % 4 == 0 && i != 0)
			sr[j++] = ' ';
		sr[j] = st[i];
	}
	sr[size + 7] = '\0';

	return sr;
}

int open(char *sr)
{
	int i = 0;

	while (*sr != '\0')
		if (*(sr++) == '1')
			i++;

	return i;
}

int main()
{
	int n = 0;

	printf("Input an integer : ");
	while (scanf("%d", &n) == 1)
	{
		while (getchar() != '\n')
			continue;

		char st[LEN];
		char sr[LEN];

		printf("%s\n", itobs(st, sr, n));
		printf("%d bit is open\n", open(sr));
		printf("Next input : ");
	}
	puts("Done.");

	system("Pause");
	return 0;
}