#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

int main(int argc, char *argv[])
{
	int ch = 0;
	FILE *fp = NULL;

	if (argc != 2)
	{
		printf("Usage : %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fopen_s(&fp, argv[1], "r");
	if (fp == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
		putc(ch, stdout);
	fclose(fp);

	system("pause");
	return 0;
}