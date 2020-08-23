#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int byte = 0;
	FILE *fp = NULL;
	int i = 0;

	if (argc == 1)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (i = 1; i < argc; i++)
	{
		fopen_s(&fp, argv[i], "r");
		if (fp == NULL)
		{
			printf("Can't open %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		while ((byte = fgetc(fp)) != EOF)
			putchar(byte);
		putchar('\n');

		if (fclose(fp) != 0)
			printf("Can't close file %s\n", argv[1]);
	}

	system("pause");
	return 0;
}