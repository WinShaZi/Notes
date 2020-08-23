#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *ch = NULL;

	if (argc != 3)
	{
		printf("Usage : %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fopen_s(&fp, argv[2], "r");
	if (fp == NULL)
	{
		printf("Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while ((ch = fgets(argv[2], SIZE, fp)) != NULL)
	{
		if (strstr(ch, argv[1]) != NULL)
			puts(ch);
	}

	system("pause");
	return 0;
}