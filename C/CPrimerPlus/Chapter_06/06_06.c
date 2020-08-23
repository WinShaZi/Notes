#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int min = 0, max = 0;

	printf("Input two integers a,b(a<b) : ");
	scanf("%d%d", &min, &max);
	printf("x          x^2        x^3\n");
	for (; min <= max; min++)
		printf("%d%12d%12d\n", min, (int)pow(min, 2), (int)pow(min, 3));

	system("pause");
	return 0;
}