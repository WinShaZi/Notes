#include <stdio.h>
#include <stdlib.h>

int main()
{
	int feet = 0;
	float cm = 0, inch = 0;
	const float feet_cm = 30.48;
	const float inch_cm = 2.54;

	printf("Input your height(CM) : ");
	while (scanf("%f", &cm) == 1 && cm >= 0)
	{
		feet = cm / feet_cm;
		inch = (cm - feet * feet_cm) / inch_cm;
		printf("%.1f cm = %d feet %.1f inches\n", cm, feet, inch);
		printf("Next input : ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}