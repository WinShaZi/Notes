#include <stdio.h>

// 匿名联合
union U
{
    char c;
    int i;
    union
    {
        float f;
        double d;
    };
};

int main(int argc, char const *argv[])
{
    union U u = {0};

    u.d = 1.1;
    printf("u.d : %e\n", u.d);

    return 0;
}
