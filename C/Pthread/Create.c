#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *Func(void *arg)
{
    int num = *((int *)arg);
    // 获取当前线程ID
    pthread_t currentPid = pthread_self();

    for (int i = 0; i < num; i++)
    {
        printf("%lu -> %d\n", currentPid, i);
    }

    return arg;
}

int main(int argc, char const *argv[])
{
    pthread_t pid1 = 0;
    pthread_t pid2 = 0;
    int arg1 = 3;
    int arg2 = 5;
    int *ret1 = NULL;
    int *ret2 = NULL;
    int result = 0;

    // 创建线程
    result = pthread_create(&pid1, NULL, Func, &arg1);
    if (result != 0)
    {
        printf("thread 1 create fail\n");
        exit(EXIT_FAILURE);
    }

    result = pthread_create(&pid2, NULL, Func, &arg2);
    if (result != 0)
    {
        printf("thread 2 create fail\n");
        exit(EXIT_FAILURE);
    }

    // 设置主线程与子线程合并
    pthread_join(pid1, (void **)&ret1);
    // 输出子线程的返回值
    printf("ret1 -> %d\n", *ret1);

    pthread_join(pid2, (void **)&ret2);
    printf("ret2 -> %d\n", *ret2);

    return 0;
}
