#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

#define LEN 40

int main()
{
	FILE *in = NULL, *out = NULL;
	int ch = 0;
	char name[LEN] = "\0";
	char filename[LEN] = "\0";
	int count = 0;

	printf("Input filename : ");
	scanf("%s", filename, LEN - 5);

	fopen_s(&in, filename, "r");
	if (in == NULL)
	{
		fprintf(stderr, "Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	strncpy_s(name, LEN, filename, LEN - 5);
	name[LEN - 5] = '\0';
	strcat_s(name, LEN, ".red");

	fopen_s(&out, name, "w");
	if (out == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);

	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");

	system("pause");
	return 0;
}