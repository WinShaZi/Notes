#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

show_array(const double ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%g ", ar[i]);
	putchar('\n');
}

double *new_d_array(int n, ...)
{
	va_list ap;
	int i;
	double* pt;

	va_start(ap, n);
	pt = (double*)malloc(n * sizeof(double));
	for (i = 0; i < n; i++)
		pt[i] = va_arg(ap, double);
	va_end(ap);

	return pt;
}

int main()
{
	double *p1 = NULL;
	double *p2 = NULL;

	p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
	p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
	show_array(p1, 5);
	show_array(p2, 4);
	free(p1);
	free(p2);

	system("pause");
	return 0;
}