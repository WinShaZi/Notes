#include<stdio.h>
#include<stdlib.h>

#define GALLON_LITER 3.785
#define MILE_KILOMETER 1.609

int main()
{
	double gallon = 0, mile = 0;
	double mile_gallon = 0, liter_kilometer = 0, liter_kilometer_100 = 0;

	printf("Input gallon : ");
	scanf("%lf", &gallon);
	printf("Input mile : ");
	scanf("%lf", &mile);
	mile_gallon = mile / gallon;
	liter_kilometer = (gallon*GALLON_LITER) / (mile*MILE_KILOMETER);
	liter_kilometer_100 = liter_kilometer * 100;
	printf("Per gallon oil can drive %.1lf mile.\n", mile_gallon);
	printf("Per 100 kilometer consume %.1lf liter oil.\n", liter_kilometer_100);

	system("pause");
	return 0;
}