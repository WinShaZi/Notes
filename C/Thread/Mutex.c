#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

int g_value = 0;
mtx_t g_mutex;

int Func(void *arg)
{
    int num = *(int *)arg;

    for (int i = 0; i < num; i++)
    {
        /**
         * if (mtx_trylock(&g_mutex) == thrd_success)
         */
        if (mtx_lock(&g_mutex) == thrd_success)
        {
            g_value += 1;
            mtx_unlock(&g_mutex);
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    thrd_t thrd1 = 0;
    thrd_t thrd2 = 0;

    int arg1 = 700000;
    int arg2 = 300000;

    /**
     * 初始化线程锁
     * mtx_plain 普通锁
     * mtx_recursive 递归锁
     * mtx_timed 定时锁
     */
    mtx_init(&g_mutex, mtx_plain);

    int ret1 = thrd_create(&thrd1, Func, &arg1);

    if (thrd_success != ret1)
    {
        puts("thrd1 create error");

        exit(EXIT_FAILURE);
    }

    int ret2 = thrd_create(&thrd2, Func, &arg2);

    if (thrd_success != ret2)
    {
        puts("thrd2 create error");

        exit(EXIT_FAILURE);
    }

    thrd_join(thrd1, NULL);
    thrd_join(thrd2, NULL);

    // 销毁线程锁
    mtx_destroy(&g_mutex);

    printf("g_value : %d\n", g_value);

    return 0;
}
