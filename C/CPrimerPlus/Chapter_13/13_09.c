#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

int main()
{
	FILE *fp = NULL;
	char words[MAX] = "\0";
	int n = 1;

	fopen_s(&fp, "Project9", "a+");
	if (fp == NULL)
	{
		fprintf(stdout, "Can't open \"Project9\" file.\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(words, MAX, fp) != NULL)
		n++;

	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	while ((fscanf_s(stdin, "%s", words, MAX) == 1) && (words[0] != '#'))
		fprintf(fp, "%d_%s\n", n++, words);
	puts("File contents:");
	rewind(fp);
	while (fscanf_s(fp, "%s", words, MAX) == 1)
		puts(words);
	puts("Done!");
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");

	system("pause");
	return 0;
}