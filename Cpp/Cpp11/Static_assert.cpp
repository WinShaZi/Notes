#include <iostream>

int main(int argc, char const *argv[])
{
    // 当表达式为假时，会提示指定报错信息
    static_assert(sizeof(int *) == 4, "64bit");

    return 0;
}
