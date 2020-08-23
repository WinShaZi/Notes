#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	double x, y;
} angle;

typedef struct
{
	double r, A;
} polar;

int main()
{
	angle an;
	polar po;

	printf("Input polar coordinate,length and angle : ");
	scanf("%lf%lf", &po.r, &po.A);
	an.x = po.r * cos(po.A * 3.1415 / 180);
	an.y = po.r * sin(po.A * 3.1415 / 180);
	printf("%-6.2lf%-6.2lf\n", an.x, an.y);

	system("pause");
	return 0;
}