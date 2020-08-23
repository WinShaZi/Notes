#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

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

int main()
{
	char so[SIZE] = "\0";
	char in[SIZE] = "\0";
	int i = 0, n = 0;

	s_gets(so, SIZE);
	while (s_gets(in, SIZE))
	{
		n = strlen(so);
		if (in[0] == '-' && in[1] == 'u' && in[2] == '\0')
			for (i = 0; i < n; i++)
				putc(toupper(so[i]), stdout);

		else if (in[0] == '-' && in[1] == 'l' && in[2] == '\0')
			for (i = 0; i < n; i++)
				putc(tolower(so[i]), stdout);
		else if ((in[0] == '-' && in[1] == 'p' && in[2] == '\0') || in[0] == '\0')
			printf("%s", so);
		else
			printf("Error");
		putchar('\n');
	}
	puts("Done");

	system("pause");
	return 0;
}