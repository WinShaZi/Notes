#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	double t_1 = (double)clock();
	double t_2 = 0;

	for (double i = 0; i < 1000000; i++)

	t_2 = (double)clock();
	printf("%lf\n", (t_2 - t_1) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}