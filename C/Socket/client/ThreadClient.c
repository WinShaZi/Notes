#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUF_SIZE 256

void *SendMsg(void *arg);
void *RecviveMsg(void *arg);

int main(int argc, char const *argv[])
{
    int clinetSock = 0;

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));

    clinetSock = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == clinetSock)
    {
        puts("socket() error");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(clinetSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        puts("connect() error");
        exit(EXIT_FAILURE);
    }

    pthread_t ptSend = 0;
    pthread_t ptReceive = 0;
    pthread_create(&ptSend, NULL, SendMsg, (void *)&clinetSock);
    pthread_create(&ptReceive, NULL, RecviveMsg, (void *)&clinetSock);
    pthread_join(ptSend, NULL);
    pthread_join(ptReceive, NULL);

    close(clinetSock);

    return 0;
}

void *SendMsg(void *arg)
{
    int clientSock = *((int *)arg);

    while (1)
    {
        char message[BUF_SIZE] = "\0";
        scanf("%s", message);
        if (strcmp(message, "q") == 0 || strcmp(message, "Q") == 0)
        {
            puts("break");
            exit(EXIT_SUCCESS);
        }

        write(clientSock, message, strlen(message));
    }

    return NULL;
}

void *RecviveMsg(void *arg)
{
    int clientSock = *((int *)arg);

    while (1)
    {
        char message[BUF_SIZE] = "\0";
        int length = read(clientSock, message, BUF_SIZE - 1);
        if (length > 0)
        {
            message[BUF_SIZE] = 0;
            fprintf(stdout, "[server] : %s\n", message);
        }
        else
        {
            return NULL;
        }
    }

    return NULL;
}