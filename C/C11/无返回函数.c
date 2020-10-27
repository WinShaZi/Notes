#include <stdio.h>
#include <stdnoreturn.h>
#include <stdlib.h>

// 由noreturn修饰的函数，不会执行以return或函数未而结束函数
noreturn void Func()
{
    printf("Hello World!");
    exit(EXIT_SUCCESS);
}

int main()
{
    Func();

    return 0;
}