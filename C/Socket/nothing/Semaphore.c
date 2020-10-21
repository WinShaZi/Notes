#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void * Input(void *arg);
void * Output(void *arg);
static sem_t sem_one;
static sem_t sem_two;
static int num = 0;

int main(int argc, char const *argv[])
{
    pthread_t pt1, pt2;
    // 三个参数分别代表：型号量对象；0则为当前线程共享，非零则为当前进程共享；指定当前信号量的值
    sem_init(&sem_one, 0, 0);
    sem_init(&sem_two, 0, 1);

    pthread_create(&pt1, NULL, Input, NULL);
    pthread_create(&pt2, NULL, Output, NULL);
 
    pthread_join(pt1, NULL);
    pthread_join(pt2, NULL);

    sem_destroy(&sem_one);
    sem_destroy(&sem_two);

    return 0;
}

void * Input(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        fputs("Input num : ", stdout);
        sem_wait(&sem_two);     // 此时sem_two减1，若sem_two为0则阻塞
        scanf("%d", &num);
        sem_post(&sem_one);     // 此时sem_two加1，若sem_one为1则阻塞
    }

    return NULL;
}

void * Output(void *arg)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sem_wait(&sem_one);
        sum += num;
        sem_post(&sem_two);
    }

    printf("Result : %d", sum);
    return NULL;
}