#include <stdio.h>
#include <stdlib.h>

int main()
{
	float pt = 0, be = 0, as = 0, ts = 0, cs = 0;

	printf("Input : ");
	scanf("%f", &be);

	pt = be / 2;
	as = be * 8;
	ts = as * 2;
	cs = ts * 3;

	printf("%.2f cup\n%.2f pint\n%.2f ounce\n%.2f soup ladle\n%.2f teaspoon\n", be, pt, as, ts, cs);

	system("pause");
	return 0;
}