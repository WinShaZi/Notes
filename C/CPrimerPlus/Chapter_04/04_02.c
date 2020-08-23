#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char name[40] = "\0";
	int width = 0;

	printf("Input you name : ");
	scanf("%s", name, 40);
	width = strlen(name) + 3;
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("[%*s]\n", width, name);

	system("pause");
	return 0;
}