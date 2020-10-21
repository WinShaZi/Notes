#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 256

// 合理关闭子进程
void ChildProcess(int sig)
{
    int status = 0;
    __pid_t pid = waitpid(-1, &status, WNOHANG);    // -1:等待任何子进程；WNOHANG:非阻塞
    printf("Remove process ID : %d\n", pid);
    if (WIFEXITED(status))      // 是否正常关闭
    {
        printf("Child process : %d\n", WEXITSTATUS(status));
    }
    else
    {
        puts("Child process closes an exception!");
    }
}

int main(int argc, char const *argv[])
{
    signal(SIGCHLD, ChildProcess);  // 当有子进程关闭时，激活信息

    int serverSock = 0;
    int clientSock = 0;

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    memset(&clientAddr, 0, sizeof(clientAddr));

    serverSock = socket(PF_INET, SOCK_STREAM, 0);

    // 设置端口复用
    int option = 1;
    if (setsockopt(serverSock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) == -1)
    {
        puts("setsockopt() error");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

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
        if (-1 == clientSock)
        {
            continue;
        }
        else
        {
            puts("New Client connected...");
        }
        __pid_t pid = fork();
        if (-1 == pid)
        {
            close(clientSock);
            continue;
        }
        if (0 == pid)       // 当前是子进程时处理数据传输
        {
            close(serverSock);
            int length = 0;
            char message[BUF_SIZE] = "\0";
            while ((length = read(clientSock, message, BUF_SIZE)) != 0)
            {
                write(clientSock, message, length);
                printf("[client %d] : %s\n", clientSock, message);
            }
            close(clientSock);
            puts("Client disconnected...");
            return 0;
        }
        else
        {
            close(clientSock);
        }
    }
    close(serverSock);

    return 0;
}
