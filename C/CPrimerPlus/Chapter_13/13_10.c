#include <stdio.h>
#include <stdlib.h>

#define SIZE 128

int main()
{
	FILE *fp = NULL;
	char file[SIZE] = "\0";
	long int i = 0;

	printf("Input filename : ");
	scanf("%s", file, SIZE);
	fopen_s(&fp, file, "r");
	if (fp == NULL)
	{
		printf("Can't open %s\n", file);
		exit(EXIT_FAILURE);
	}
	printf("Input file start place : ");
	while (scanf("%ld", &i) && i >= 0)
	{
		char ch;
		fseek(fp, i, SEEK_SET);
		while ((ch = getc(fp)) != '\n')
		{
			putchar(ch);
		}
		putchar('\n');
	}
	fclose(fp);

	system("pause");
	return 0;
}