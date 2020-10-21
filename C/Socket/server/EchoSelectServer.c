#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    int serverSock = 0;
    int clientSock = 0;

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;

    struct timeval timeout = {3, 0};

    fd_set reads;
    fd_set copyReads;

    memset(&serverAddr, 0, sizeof(serverAddr));
    memset(&clientAddr, 0, sizeof(clientAddr));

    serverSock = socket(PF_INET, SOCK_STREAM, 0);

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
        exit(EXIT_SUCCESS);
    }

    FD_ZERO(&reads);        // 清零
    FD_SET(serverSock, &reads);     // 将服务端套接字注册到reads
    int fdMax = serverSock;

    while (1)
    {
        copyReads = reads;      // 更改操作均更改reads，copyReads保存上一次的状态

        int fdNum = select(fdMax + 1, &copyReads, 0, 0, &timeout);      // 第一个参数表示选取范围，即最大值加1
        if (-1 == fdNum)
        {
            puts("select() error");
            break;
        }
        if (0 == fdNum)
        {
            continue;
        }

        for (int i = 0; i < fdMax + 1; i++)
        {
            if (FD_ISSET(i, &copyReads))    // 此位置中是否有文件描述符
            {
                if (i == serverSock)        // 第一次连接则进入此路径，80行设置为客户端，此次连接再无法进入此路径
                {
                    socklen_t addrLength = sizeof(clientAddr);
                    clientSock = accept(serverSock, (struct sockaddr *)&clientAddr, &addrLength);
                    FD_SET(clientSock, &reads);
                    if (fdMax < clientSock)     // 当客户端套接字大于当前最大指时，最大值为当前套接字
                    {
                        fdMax = clientSock;
                    }
                    printf("Connect client : %d\n", clientSock);
                }
                else
                {
                    char message[BUF_SIZE] = "\0";
                    int length = read(i, message, BUF_SIZE);
                    if (length > 0)
                    {
                        write(i, message, BUF_SIZE);
                        printf("[client] : %s\n", message);
                    }
                    else
                    {
                        FD_CLR(i, &reads);      // 从reads中清除该客户端的套接字
                        close(i);
                        printf("Closed client : %d\n", i);
                    }
                }
            }
        }
    }

    return 0;
}
