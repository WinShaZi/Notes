#include <stdio.h>
#include <stdlib.h>

#define LOW -459.588

Temperatures(double fah)
{
	const double A = 5.0, B = 9.0, C = 32.0, D = 273.16;

	printf("Fahrenit : %.2lf\n", fah);
	printf("Centigrade ; %.2lf\n", A / B * (fah - C));
	printf("Kelvin : %.2lf\n", A / B * (fah - C) + D);
}

int main()
{
	double fah = 0;

	printf("Input the number of Fahrenheit : ");
	while (scanf("%lf", &fah) == 1)
	{
		if (fah < LOW)
		{
			printf("Next input : ");
			continue;
		}
		Temperatures(fah);
		printf("Next input : ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}