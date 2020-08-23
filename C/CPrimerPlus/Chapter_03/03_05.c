#include <stdio.h>
#include <stdlib.h>

int main()
{
	int year = 0;
	double second = 0;

	printf("Input your age : ");
	scanf("%d", &year);
	second = year * 3.156e7;
	printf("%d years is %.3e seconds\n", year, second);

	system("pause");
	return 0;
}