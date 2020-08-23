#include <stdio.h>
#include <stdlib.h>

int main()
{
	float quart = 0;
	double H2O = 0;

	printf("Input the quarts : ");
	scanf("%f", &quart);
	H2O = quart * 950 / 3.0e-23;
	printf("%.2f quarts have %.3e water molecule.\n", quart, H2O);

	system("pause");
	return 0;
}