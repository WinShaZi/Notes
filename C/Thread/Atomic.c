#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <threads.h>

#define MAX_SIZE 100
atomic_int g_value = 0;

int Func(void *arg)
{
    int num = *(int *)arg;

    for (int i = 0; i < num; i++)
    {
        // 原子加法
        atomic_fetch_add(&g_value, 1);
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    thrd_t thrdArr[MAX_SIZE];
    int arg = MAX_SIZE * MAX_SIZE * MAX_SIZE;

    // 创建100条线程，均累加100万次
    for (int i = 0; i < MAX_SIZE; i++)
    {
        thrd_create(&thrdArr[i], Func, &arg);
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        thrd_join(thrdArr[i], NULL);
    }

    printf("g_value : %.10e\n", (double)g_value);

    return 0;
}
