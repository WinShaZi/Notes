#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

#define MAX_SIZE 100000000

int g_value = 0;
mtx_t g_mutex;
cnd_t g_condition;

int Add(void *arg)
{
    while (1)
    {
        mtx_lock(&g_mutex);

        if (g_value < MAX_SIZE)
        {
            g_value++;
        }
        else
        {
            puts("---FULL---");
            /**
             * 向所有所有条件变量发送信号
             * cnd_broadcast(&g_condition);
             */
            cnd_signal(&g_condition);
        }

        mtx_unlock(&g_mutex);
    }

    return 0;
}

int Sub(void *arg)
{
    while (1)
    {
        mtx_lock(&g_mutex);
        cnd_wait(&g_condition, &g_mutex);

        while (g_value > 0)
        {
            g_value--;
        }
        puts("---EMPTY---");

        mtx_unlock(&g_mutex);
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    thrd_t thrd1 = 0;
    thrd_t thrd2 = 0;

    mtx_init(&g_mutex, mtx_plain);
    cnd_init(&g_condition);

    int ret1 = thrd_create(&thrd1, Add, NULL);

    if (thrd_success != ret1)
    {
        puts("thrd1 create error");

        exit(EXIT_FAILURE);
    }

    int ret2 = thrd_create(&thrd2, Sub, NULL);

    if (thrd_success != ret2)
    {
        puts("thrd2 create error");

        exit(EXIT_FAILURE);
    }

    thrd_join(thrd1, NULL);
    thrd_join(thrd2, NULL);

    mtx_destroy(&g_mutex);
    cnd_destroy(&g_condition);

    return 0;
}
