#include <stdio.h>
#include <stdlib.h>

int main()
{
	char name[40] = "\0";
	float inch = 0;

	printf("Input your name : ");
	scanf("%s", name, 40);
	printf("Input yur height(in) : ");
	scanf("%f", &inch);
	printf("%s,you are %.3f feet tall\n", name, inch / 10);

	system("pause");
	return 0;
}