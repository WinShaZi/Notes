#include <stdio.h>
#include <stdlib.h>

copy_arr(double target1[], double source[], int n)
{
	int i = 0;

	printf("target1[5] = {");
	for (i = 0; i < n; i++)
	{
		target1[i] = source[i];
		printf(" %.1lf", target1[i]);
		if (i < 4)
			putchar(',');
	}
	printf(" }\n");
}

copy_ptr(double *target2, double *source, int n)
{
	int i = 0;

	printf("target2[5] = {");
	for (i = 0; i < n; i++)
	{
		*(target2 + i) = *(source + i);
		printf(" %.1lf", *(target2 + i));
		if (i < 4)
			putchar(',');
	}
	printf(" }\n");
}

copy_ptrs(double *target3, double *source, double *n)
{
	int i = 0;

	printf("target3[5] = {");
	while (source < n)
	{
		*target3 = *source;
		printf(" %.1lf", *target3);
		target3++;
		source++;
		if (i++ < 4)
			putchar(',');
	}
	printf(" }\n");
}

int main()
{
    double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[5] = {0};
	double target2[5] = {0};
	double target3[5] = {0};

	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);

	system("pause");
	return 0;
}