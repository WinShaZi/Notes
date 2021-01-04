#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUF_SIZE 256
#define MAX_CLIENT 128

int clientNum = 0;
int arrClient[MAX_CLIENT] = {0};
pthread_mutex_t mutex;

void SendMsg(char *msg, int length);
void *DealClient(void *arg);

int main(int argc, char const *argv[])
{
    int serverSock = 0;
    int clientSock = 0;

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    memset(&clientAddr, 0, sizeof(clientAddr));

    serverSock = socket(PF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        puts("bind() error");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSock, 5) == -1)
    {
        puts("listen() error");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        socklen_t sockLength = sizeof(clientAddr);
        clientSock = accept(serverSock, (struct sockaddr *)&clientAddr, &sockLength);

        pthread_mutex_lock(&mutex);
        arrClient[clientNum++] = clientSock;
        pthread_mutex_unlock(&mutex);

        pthread_t pt = 0;
        // 每加入一个客户端连接则新建一条线程用于处理客户端
        pthread_create(&pt, NULL, DealClient, (void *)&clientSock);
        // 处理客户端的线程设置为分离，避免主线程等待
        pthread_detach(pt);
        printf("connect client socket : %d\n", clientSock);
    }
    close(serverSock);

    return 0;
}

void *DealClient(void *arg)
{
    int clientSock = *((int *)arg);

    char msg[BUF_SIZE] = "\0";
    int length = 0;

    while ((length = read(clientSock, msg, BUF_SIZE)) > 0)
    {
        SendMsg(msg, length);
    }

    pthread_mutex_lock(&mutex);

    // 移除断开连接的客户端，将后续序列向左移动一位
    for (int i = 0; i < clientNum; i++)
    {
        if (clientSock == arrClient[i])
        {
            while (i < clientNum)
            {
                arrClient[i] = arrClient[i + 1];
                i++;
            }
            break;
        }
    }
    clientNum--;
    pthread_mutex_unlock(&mutex);

    close(clientSock);

    return NULL;
}

void SendMsg(char *msg, int length)
{
    pthread_mutex_lock(&mutex);
    // 对所有已连接的服务端发送消息
    for (int i = 0; i < clientNum; i++)
    {
        write(arrClient[i], msg, length);
    }
    printf("[client] : %s\n", msg);
    pthread_mutex_unlock(&mutex);
}
