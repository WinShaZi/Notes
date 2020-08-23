#include <stdio.h>
#include <stdlib.h>

int main()
{
	double num_1[8] = {0}, num_2[8] = {0};

	printf("Input 8 number : ");
	for (int i = 0; i < 8; i++)
		scanf("%lf", &num_1[i]);
	num_2[0] = num_1[0];
	for (int i = 1; i < 8; i++)
		num_2[i] = num_2[i - 1] + num_1[i];
	for (int j = 0; j < 8; j++)
		printf("%-8.3f ", num_1[j]);
	printf("\n");
	for (int k = 0; k < 8; k++)
		printf("%-8.3f ", num_2[k]);
	printf("\n");

	system("pause");
	return 0;
}