#include <stdio.h>
#include <pthread.h>

int g_value = 0;
pthread_mutex_t g_mutex;

void *Func(void *arg)
{
    int num = *((int *)arg);

    for (int i = 0; i < num; i++)
    {
        /**
         * 阻塞加锁
         * pthread_mutex_lock(&g_mutex);
         */
        // 非阻塞试图加锁，成功返回0
        if (pthread_mutex_trylock(&g_mutex) == 0)
        {
            g_value += 1;
            pthread_mutex_unlock(&g_mutex);
        }
    }

    return arg;
}

int main(int argc, char const *argv[])
{
    pthread_t pid1 = 0;
    pthread_t pid2 = 0;
    int arg = 10000000;

    // 初始化线程锁
    pthread_mutex_init(&g_mutex, NULL);

    pthread_create(&pid1, NULL, Func, &arg);
    pthread_create(&pid2, NULL, Func, &arg);

    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);

    // 销毁线程锁
    pthread_mutex_destroy(&g_mutex);

    printf("g_value : %d\n", g_value);

    return 0;
}
