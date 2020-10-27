#include <stdio.h>
#include <math.h>
#include <complex.h>

int main()
{
    double complex z1 = I * I; // 虚数单位平方
    printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));

    return 0;
}
