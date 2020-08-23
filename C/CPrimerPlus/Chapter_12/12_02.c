
//pe12-2a.h
//*******************************************************************************************

#define HUNDRED 100

void set_mode(int);
void get_info();
void show_info();

double mileage;
double fuel;
int n;


//*******************************************************************************************

//p12-2a.c
//*******************************************************************************************

#include<stdio.h>
#include"pe12-2a.h"

void set_mode(int mode)
{
	if (mode >= 3)
	{
		if (n == 0)
			printf("Invalid mode specified.Mode 0(EU) used.\n");
		else
			printf("Invalid mode specified.Mode 1(US) used.\n");
	}
	else
		n = mode;
}


void get_info()
{
	if (n == 0)
	{
		printf("Enter distance traveled in kilometers : ");
		while (!scanf("%lf", &mileage) || mileage <= 0)
			continue;
		printf("Enter fuel consumed in liters : ");
		while (!scanf("%lf", &fuel) || fuel <= 0)
			continue;
	}
	if (n == 1)
	{
		printf("Enter distance traveled in miles : ");
		while (!scanf("%lf", &mileage) || mileage <= 0)
			continue;
		printf("Enter fuel consumed in gallons : ");
		while (!scanf("%lf", &fuel) || fuel <= 0)
			continue;
	}
}

void show_info()
{
	if (n == 0)
		printf("Fuel consumption is %.1lf liters per 100 km.\n", HUNDRED * fuel / mileage);
	if (n == 1)
		printf("Fuel consumption is %.1lf liters per 100 km.\n", mileage / fuel);
}

//*******************************************************************************************

//pe12-2b.c
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "pe12-2a.h"

int main()
{
	int mode;

	printf("Enter 0 for metric mode,1 for us mode : ");
	while (scanf("%d", &mode) && mode >= 0)
	{
		set_mode(mode);
		if (n == -1)
			break;
		get_info();
		show_info();
		printf("Enter 0 for metric mode,1 for us mode");
		printf(" (-1 to quit): ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}

//********************************************************************************************