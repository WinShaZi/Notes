
//diceroll.h
//*******************************************************************************************

extern int roll_count;
extern int num[100];
extern int sets;

int roll_n_dice(int dice, int sides);

//*******************************************************************************************

//diceroll.c
//*******************************************************************************************

#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>

int roll_count = 0;
int num[100];
int sets;

static int rollem(int sides, int dice)
{
	int roll = 0;

	roll = rand() % sides + 1;
	++roll_count;

	return roll;
}

int roll_n_dice(int dice, int sides)
{
	int d = 0;
	int total = 0;

	if (sides < 2)
	{
		printf("Need at least 2 sides.\n");
		return -2;
	}
	if (dice < 1)
	{
		printf("Need at least 1 die.\n");
		return -1;
	}
	for (int i = 0; i < sets; i++)
	{
		for (d = 0; d < dice; d++)
			total += rollem(sides, dice);
		num[i] = total;
		if (d == dice)
			total = 0;
	}
	return total;
}

//*******************************************************************************************

//manydice.c
//*******************************************************************************************

#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int dice = 0;
	int sides = 0;
	extern int sets;
	extern int num[100];
	extern int roll_count;

	srand((unsigned int)time(0));
	printf("Enter the number of sets, enter q to stop : ");
	while (scanf("%d", &sets))
	{
		if (sets <= 0)
			continue;
		printf("How many sides and how many dice? : ");
		if (scanf("%d%d", &sides, &dice) != 2)
		{
			if (sides <= 3 && sides <= 0)
				continue;
			else
			{
				printf("How should have entered an integer.");
				printf(" Let's begin again.\n");
				while (getchar() != '\n')
					continue;
				printf("How many sides? Enter q to stop.\n");
				continue;
			}
		}
		roll_n_dice(dice, sides);
		printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
		for (int i = 0; i < sets; i++)
		{
			printf("%-6d", num[i]);
			if ((i + 1) % 6 == 0)
				putchar('\n');
		}
		printf("\nHow many sides? Enter q to stop : ");
	}
	printf("The rollem() function was called %d times.\n", roll_count);
	printf("GOOD FORTURE TO YOU!\n");

	system("pause");
	return 0;
}

//*******************************************************************************************