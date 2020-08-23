#include <stdio.h>
#include <stdlib.h>

void jolly();
void deny();

int main()
{
	jolly();
	jolly();
	jolly();
	deny();

	system("pause");
	return 0;
}

void jolly()
{
	printf("For he's a jolly goo fellow!\n");
}

void deny()
{
	printf("Which nobody can deny!\n");
}