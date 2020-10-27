#include <stdio.h>

// 匿名结构体
struct A
{
    char c;
    int i;
    struct
    {
        float f;
        double d;
    };
};

int main(int argc, char const *argv[])
{
    /**
     * 初始化方法
     * struct A a = {.c = '0', .i = 'i', .f = '2.2', .d = '3.3'};
     */
    struct A a = {'0', 1, {2.2, 3, 3}};

    printf("a.c : %d\n", a.c);
    printf("a.i : %d\n", a.i);
    printf("a.f : %f\n", a.f);
    printf("a.d : %e\n", a.d);

    return 0;
}
