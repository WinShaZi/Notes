#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int byte = 0;
	FILE *fp_1 = NULL;
	FILE *fp_2 = NULL;

	if (argc != 3)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fopen_s(&fp_1, argv[1], "rb");
	if (fp_1 == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fopen_s(&fp_2, argv[2], "wb");
	if (fp_2 == NULL)
	{
		printf("Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((byte = getc(fp_1)) != EOF)
		putc(byte, fp_2);
	if (fclose(fp_1) != 0)
		printf("Can't close %s\n", argv[1]);
	if (fclose(fp_2) != 0)
		printf("Can't close %s\n", argv[2]);

	system("pause");
	return 0;
}