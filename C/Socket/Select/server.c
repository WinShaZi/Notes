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

    struct timeval timeout = {.tv_sec = 3, .tv_usec = 0};

    fd_set sockRecord;     // 记录注册的socket
    fd_set lastSockRecord; // 记录上次注册的socket

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
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

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

    FD_ZERO(&sockRecord);            // 清零
    FD_SET(serverSock, &sockRecord); // 将服务端套接字注册到sockRecord
    int fdMax = serverSock + 1;

    while (1)
    {
        lastSockRecord = sockRecord; // 更改操作均更改reads，copyReads保存上一次的状态

        int fdNum = select(fdMax, &lastSockRecord, 0, 0, &timeout); // 第一个参数表示选取范围
        if (-1 == fdNum)
        {
            puts("select() error");
            break;
        }
        if (0 == fdNum)
        {
            continue;
        }

        // 遍历[0, fdMax - 1]的所有文件描述符
        for (int i = 0; i < fdMax; i++)
        {
            if (FD_ISSET(i, &lastSockRecord) > 0) // 该文件描述符可读写则为真
            {
                /**
                 * 当serverSock有事件时，则注册当前请求连接的客户端socket
                 * 当clientSock有时间时，则处理与客户端的交互
                 */
                if (i == serverSock)
                {
                    socklen_t addrLength = sizeof(clientAddr);
                    // 接收客户端的连接申请
                    clientSock = accept(serverSock, (struct sockaddr *)&clientAddr, &addrLength);
                    // 将客户端socket注册到sockRecord中
                    FD_SET(clientSock, &sockRecord);
                    if (fdMax < clientSock) // 当客户端套接字大于当前最大值时，最大值为当前套接字 + 1
                    {
                        fdMax = clientSock + 1;
                    }
                    printf("connect client : %d\n", clientSock);
                }
                else
                {
                    clientSock = i;

                    char message[BUF_SIZE] = "\0";
                    int length = read(clientSock, message, BUF_SIZE);
                    // 当收到客户端发送的数据时则回复，若未收到则关闭socket
                    if (length > 0)
                    {
                        write(clientSock, message, BUF_SIZE);
                        printf("[client %d] : %s\n", clientSock, message);
                    }
                    else
                    {
                        FD_CLR(i, &sockRecord); // 从sockRecord中清除该客户端的套接字
                        close(i);
                        printf("closed client : %d\n", clientSock);
                    }
                }
            }
        }
    }

    return 0;
}
