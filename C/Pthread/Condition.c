#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 10

typedef struct Repository
{
    int arr[MAX_SIZE];
    int size;
} Repository;

Repository repository = {{0}, 0};

pthread_mutex_t g_mutex;
pthread_cond_t g_condition;

void *Input(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&g_mutex);
        // 当仓库不满时持续增加
        if (repository.size < MAX_SIZE)
        {
            repository.arr[repository.size] = rand();
            printf("Input -> %d\n", repository.arr[repository.size]);
            repository.size++;
            sleep(1);
        }
        else
        {
            // 仓库已满则通知等待线程
            pthread_cond_signal(&g_condition);
        }
        pthread_mutex_unlock(&g_mutex);
    }
}

void *OutPut(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&g_mutex);
        // 等待仓库已满通知
        pthread_cond_wait(&g_condition, &g_mutex);
        while (repository.size > 0)
        {
            printf("OutPut -> %d\n", repository.arr[repository.size - 1]);
            repository.arr[repository.size - 1] = 0;
            repository.size--;
            sleep(1);
        }
        pthread_mutex_unlock(&g_mutex);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t pid1 = 0;
    pthread_t pid2 = 0;

    pthread_mutex_init(&g_mutex, NULL);
    pthread_cond_init(&g_condition, NULL);

    pthread_create(&pid1, NULL, Input, NULL);
    pthread_create(&pid2, NULL, OutPut, NULL);

    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);

    pthread_mutex_destroy(&g_mutex);
    pthread_cond_destroy(&g_condition);

    return 0;
}
