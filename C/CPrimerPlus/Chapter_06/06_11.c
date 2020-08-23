#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num[8] = {0}, i = 0;

	printf("Input 8 integers : ");
	for (i = 0; i < 8; i++)
		scanf("%d", &num[i]);
	for (i = 7; i >= 0; i--)
		printf("%d ", num[i]);
	printf("\n");

	system("pause");
	return 0;
}