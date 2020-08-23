#include <stdio.h>
#include <stdlib.h>

#define T_AVER(X,Y) (1/((1/(X)+1/(Y))/2))

int main()
{
	float x = 0, y = 0;

	printf("Input two integer number : ");
	scanf("%f%f", &x, &y);
	printf("%.2f\n", T_AVER(x, y));

	system("pause");
	return 0;
}