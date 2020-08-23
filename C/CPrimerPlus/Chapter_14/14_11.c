#include <stdio.h>
#include <stdlib.h>      
#include <math.h>

#define SIZE 100

double a_1(double a)
{
	return pow(a, 1);
}

double a_2(double a)
{
	return pow(a, 2);
}

double a_3(double a)
{
	return pow(a, 3);
}

double a_a(double a)
{
	return pow(a, a);
}

transform(double * source, double * target, int n, double(*sin)(double a))
{
	for (int i = 0; i < n; i++)
		source[i] = i + 1;

	for (int i = 0; i < n; i++)
		*(target++) = sin(*(source++));
}


print(double *target)
{
	for (int i = 0; i < 5; i++)
		printf("%.2f\n", *(target++));
	putchar('\n');
}

show(double *source, double *target, int n, double(*sin)(double a))
{
	sin = a_1;
	transform(source, target, n, sin);
	print(target);

	sin = a_2;
	transform(source, target, n, sin);
	print(target);

	sin = a_3;
	transform(source, target, n, sin);
	print(target);

	sin = a_a;
	transform(source, target, n, sin);
	print(target);

}

int main()
{

	double(*sin)(double a) = a_1;
	double source[SIZE] = {0};
	double target[SIZE] = {0};

	show(source, target, SIZE, sin);
	
	system("pause");
	return 0;
}