#include <stdio.h>
#include <stdlib.h>

#define BIT 8

int bstr(const char * str)
{
	int num = 0;

	while (*str != '\0')
	{
		if (*str != '0'&&*str != '1')
			exit(EXIT_FAILURE);
		num = 2 * num + (*str++ - '0');
	}

	return num;
}

char *itobs(int n, char *st, char *sr)
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

int main(int argc, char * argv[])
{
	int i = 0;
	int j = 0;
	char st[BIT * sizeof(int) + 1];
	char sr[BIT * sizeof(int) + 8];

	if (argc != 3)
	{
		puts("Error.");
		exit(EXIT_FAILURE);
	}

	i = bstr(argv[1]);
	j = bstr(argv[2]);
	
	printf("%s = %s\n", argv[1], itobs(i, st, sr));
	printf("%s = %s\n", argv[2], itobs(j, st, sr));
	printf("~%s = %s\n", argv[1], itobs(~i, st,sr));
	printf("~%s = %s\n", argv[2], itobs(~j, st,sr));
	printf("%s & %s= %s\n", argv[1], argv[2], itobs(i & j, st, sr));
	printf("%s | %s= %s\n", argv[1], argv[2], itobs(i | j, st, sr));
	printf("%s ^ %s= %s\n", argv[1], argv[2], itobs(i ^ j, st, sr));

	system("pause");
	return 0;
}