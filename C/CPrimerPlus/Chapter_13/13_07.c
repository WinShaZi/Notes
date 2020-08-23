#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp_1 = NULL, *fp_2 = NULL;
	char ch_1 = '\0', ch_2 = '\0';

	if (argc != 4)
	{
		printf("Usage : %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fopen_s(&fp_1, argv[1], "r");
	fopen_s(&fp_2, argv[2], "r");
	if (fp_1 == NULL || fp_2 == NULL)
	{
		printf("Can't open file\n");
		exit(EXIT_FAILURE);
	}

	while ((ch_1 = getc(fp_1)) != EOF || (ch_2 = getc(fp_2)) != EOF)
	{
		if (argv[3][0] == 'a' || argv[3][0] == 'b')
		{
			while ((ch_1 = getc(fp_1)) != EOF && ch_1 != '\n')
				putchar(ch_1);
			if (argv[3][0] == 'a')
				putchar('\n');
			else
				putchar(' ');
		}
		else
		{
			printf("Mode error\n");
			exit(EXIT_FAILURE);
		}
		while ((ch_2 = getc(fp_2)) != EOF && ch_2 != '\n')
			putchar(ch_2);
		putchar('\n');
	}
	fclose(fp_1);
	fclose(fp_2);

	system("pause");
	return 0;
}