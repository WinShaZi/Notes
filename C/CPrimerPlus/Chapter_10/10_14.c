#include<stdio.h>
#include<stdlib.h>

enter(double array[][5], int i)
{
	int  j = 0;

	for (i = 0; i < 3; i++)
	{
		printf("Input 5 number : ");
		for (j = 0; j < 5; j++)
			scanf("%lf", &array[i][j]);
	}
}

double average(double array[][5], int i, int num)
{
	int j = 0;
	double sum = 0;

	for (j = 0; j < 5; j++)
		sum += array[i][j];

	return sum / 5;
}

maximum(double array[][5], int i)
{
	int j = 0;
	double max = array[0][0];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
		{
			if (max < array[i][j])
				max = array[i][j];
		}
	printf("The array maximum number is %.2lf\n", max);
}

int main()
{
	int n = 0;
	double array[3][5] = {0};

	enter(array, 3);
	for (n = 0; n < 3; n++)
		printf("The %d line average is %.2lf\n", n + 1, average(array, n, 3));
	maximum(array, 3);

	system("pause");
	return 0;
}