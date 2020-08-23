#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char ch = '\0';
	int i = 0;

	if (argc < 3)
	{
		if (argc != 2)
		{
			printf("Usage : %s filename\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	for (i = 2; i < argc; i++)
	{
		int n = 0;
		fopen_s(&fp, argv[i], "r");
		if (fp == NULL)
		{
			printf("Can't open %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		while ((ch = getc(fp)) != EOF)
		{
			if (ch == argv[1][0])
				n++;
		}
		printf("%s file : %d %c\n", argv[i], n, argv[1][0]);
		if (fclose(fp) != 0)
		{
			printf("Can't close %s\n", argv[i]);
			continue;
		}
	}

	system("pause");
	return 0;
}