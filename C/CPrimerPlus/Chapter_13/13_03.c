#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 256

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char up[SIZE] = "\0";
	char ch = '\0';
	int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage : %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fopen_s(&fp, argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		ch = toupper(ch);
		up[i++] = ch;
	}
	up[i] = '\0';
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fopen_s(&fp, argv[1], "w");
	if (fp == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fprintf(fp, "%s", up);
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	system("pause");
	return 0;
}