
//pe12-2a.h
//*******************************************************************************************

#define HUNDRED 100

void set_mode(int, int *);
double get_info(int *);
void show_info(int *);

//*******************************************************************************************

//pe12-2a.c
//*******************************************************************************************

#include <stdio.h>
#include "pe12-2a.h"

void set_mode(int mode, int *n)
{
	if (mode >= 3)
	{
		if (n[0] == 0)
			printf("Invalid mode specified.Mode 0(EU) used.\n");
		else
			printf("Invalid mode specified.Mode 1(US) used.\n");
	}
	else
		n[0] = mode;
}


double get_info(int *n)
{
	double mileage, fuel;

	if (n[0] == 0)
	{
		printf("Enter distance traveled in kilometers : ");
		while (!scanf("%lf", &mileage) || mileage <= 0)
			continue;
		printf("Enter fuel consumed in liters : ");
		while (!scanf("%lf", &fuel) || fuel <= 0)
			continue;

		return HUNDRED * fuel / mileage;
	}
	else
	{
		printf("Enter distance traveled in miles : ");
		while (!scanf("%lf", &mileage) || mileage <= 0)
			continue;
		printf("Enter fuel consumed in gallons : ");
		while (!scanf("%lf", &fuel) || fuel <= 0)
			continue;

		return mileage / fuel;
	}
}

void show_info(int *n)
{
	if (n[0] == 0)
		printf("Fuel consumption is %.1lf liters per 100 km.\n", get_info(n));
	if (n[0] == 1)
		printf("Fuel consumption is %.1lf miles per gallon.\n", get_info(n));
}

//*******************************************************************************************

//pe12-2b.c
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "pe12-2a.h"

int main()
{
	int mode = 0;
	int n[1] = {0};

	n[0] = 1;
	printf("Enter 0 for metric mode,1 for us mode: ");
	while (scanf("%d", &mode) && mode >= 0)
	{
		set_mode(mode, n);
		show_info(n);
		printf("Enter 0 for metric mode,1 for us mode");
		printf(" (-1 to quit): ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}

//*******************************************************************************************