#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdbool.h>

#define BUF_SIZE 256

void ReadRoutine(int sock, char *message)
{
    while (1)
    {
        int length = read(sock, message, BUF_SIZE);
        if (0 == length)
        {
            puts("server disconnected");
            return;
        }
        message[length] = 0;
        printf("[server] : %s\n", message);
    }
}

void WriteRoutine(int sock, char *message)
{
    while (1)
    {
        printf("Input message(q to quit) : ");
        scanf("%s", message);
        if (strcmp(message, "q") == 0 || strcmp(message, "Q") == 0)
        {
            /**
             * SHUT_RD：断开输入流。套接字无法接收数据（即使输入缓冲区收到数据也被抹去），无法调用输入相关函数
             * SHUT_WR：断开输出流。套接字无法发送数据，但如果输出缓冲区中还有未传输的数据，则将传递到目标主机
             * SHUT_RDWR：同时断开 I/O 流。相当于分两次调用shutdown()，其中一次以SHUT_RD为参数，另一次以SHUT_WR为参数
             */
            shutdown(sock, SHUT_WR);
            return;
        }
        write(sock, message, BUF_SIZE);
    }
}

int main(int argc, char const *argv[])
{
    int clientSock;
    struct sockaddr_in serverAddr;

    clientSock = socket(PF_INET, SOCK_STREAM, 0);

    int option = 1;
    setsockopt(clientSock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(clientSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        puts("connect() error");
        exit(EXIT_FAILURE);
    }

    char message[BUF_SIZE] = "\0";

    __pid_t pid = fork();
    // 子进程处理写，父进程处理读
    if (0 == pid)
    {
        WriteRoutine(clientSock, message);
    }
    else
    {
        ReadRoutine(clientSock, message);
    }

    return 0;
}
