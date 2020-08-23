#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define CSIZE 4
#define NUM 3

struct name
{
	char fname[SIZE];
	char lname[SIZE];
};

struct student
{
	struct name na;
	float grad[NUM];
	float average;
};

int main()
{
	struct student message[CSIZE]=
	{
		{.na.fname = "AAA",.na.lname = "aaa"},
		{.na.fname = "BBB",.na.lname = "bbb"},
		{.na.fname = "CCC",.na.lname = "ccc"},
		{.na.fname = "DDD",.na.lname = "ddd"}
	};

	int i = 0;
	float x = 0, y = 0, z = 0;
	float count = 0.0;

	printf("Input the %s three grades :\n", message[i].na.lname);
	while (scanf("%f%f%f", &x, &y, &z) == NUM)
	{
		message[i].grad[0] = x;
		message[i].grad[1] = y;
		message[i].grad[2] = z;
		message[i].average = (x + y + z) / NUM;
		i++;
		if (i >= CSIZE)
			break;
		else
			while (getchar() != '\n')
				continue;
		system("CLS");
		printf("Input the %s three grades :\n", message[i].na.lname);
	}

	for (i = 0; i < CSIZE; i++)
	{
		x = message[i].grad[0];
		y = message[i].grad[1];
		z = message[i].grad[2];
		
		printf("\n%s %s :  %.1f  %.1f  %.1f\n", message[i].na.lname, message[i].na.fname, x, y, z);
		printf("%s average : %.1f\n", message[i].na.lname, message[i].average);
		count += message[i].average;
	}
	printf("\nThe class average : %.1f\n", count / CSIZE);

	system("pause");
	return 0;
}