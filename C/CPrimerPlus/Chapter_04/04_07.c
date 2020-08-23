#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main()
{
	double A = 1.0 / 3.0;
	float B = 1.0 / 3.0;

	printf("The double pointinf value : \n%.6e %.12e %.16e\n", A, A, A);
	printf("The double pointinf value : \n%.6f %.12f %.16f\n", B, B, B);
	printf("FLT_DIG:%d\nDBL_DIG : %d\n", FLT_DIG, DBL_DIG);

	system("pause");
	return 0;
}