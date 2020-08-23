#include <stdio.h>
#include <stdlib.h>

int main()
{
	int int_1 = 0, int_2 = 0;
	float float_1 = 0;
	double double_1 = 0;

	int_1 = INT_MAX;
	printf("int overflow : %d\n", int_1 + 1);
	int_2 = INT_MIN;
	printf("int underflow : %d\n", int_2 - 1);
	float_1 = 3.4e40;
	printf("float overflow : %f\n", float_1);
	double_1 = -1.7e-324;
	printf("double underflow%e\n", double_1);

	system("pause");
	return 0;
}