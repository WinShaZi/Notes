#include <stdio.h>
#include <stdlib.h>

void two();
void one_three();

int main()
{
	printf("Starting now :\n");
	one_three();

	system("pause");
	return 0;
}

void two()
{
	printf("two\n");
}

void one_three()
{
	printf("one\n");
	two();
	printf("three\n");
}