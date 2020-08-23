#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest)
{
	size_t bytes = 0;
	static char temp[BUFSIZE] = "\0"; 

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}

int main(int argc,char *argv[])
{
	FILE *fa = NULL, *fs = NULL;
	int files = 0;  
	int i = 0;

	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fopen_s(&fa, argv[1], "a+");
	if (fa == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	puts("Enter name of first source file :");
	for (i = 2; i < argc; i++)
	{
		fopen_s(&fs, argv[i], "r");
		if (strcmp(argv[i], argv[1]) == 0)
			fputs("Can't append file to itself\n", stderr);
		else if (fs == NULL)
			fprintf(stderr, "Can't open %s\n", argv[i]);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\n", argv[i]);
			if (ferror(fa) != 0)
				fprintf(stderr, "Error in writing file %s.\n", argv[1]);
			fclose(fs);
			files++;
			printf("File %s appended.\n", argv[i]);
		}
	}
	printf("Done appending. %d files appended.\n", files);
	fclose(fa);

	system("pause");
	return 0;
}