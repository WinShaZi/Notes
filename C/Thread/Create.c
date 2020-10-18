#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <threads.h>

int Func(void *arg)
{
    struct timespec sleepTime = {
        .tv_sec = 0,
        .tv_nsec = 500 * 1000000};
    for (int i = 0; i < 3; i++)
    {
        // 休眠500ms
        thrd_sleep(&sleepTime, NULL);
        printf("%lu => %d\n", thrd_current(), i);
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    thrd_t thrd1 = 0;
    thrd_t thrd2 = 0;

    puts("--------begin---------");

    // 第三个参数为向函数传递的参数
    int ret1 = thrd_create(&thrd1, Func, NULL);

    if (thrd_success != ret1)
    {
        puts("thrd1 create error");

        exit(EXIT_FAILURE);
    }

    int ret2 = thrd_create(&thrd2, Func, NULL);

    if (thrd_success != ret2)
    {
        puts("thrd2 create error");

        exit(EXIT_FAILURE);
    }

    // 第二个参数为指定返回值
    thrd_join(thrd1, NULL);
    thrd_join(thrd2, NULL);

    puts("---------end----------");

    return 0;
}
