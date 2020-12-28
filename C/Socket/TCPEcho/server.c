#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    int serverSock = 0;
    int clientSock = 0;

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    memset(&clientAddr, 0, sizeof(clientAddr));

    // 建立socket时采用PF_INET
    serverSock = socket(PF_INET, SOCK_STREAM, 0);

    // 设置socket地址时采用AF_INET（ipv4）
    serverAddr.sin_family = AF_INET;
    // 设置服务端端口号
    serverAddr.sin_port = htons(8080);
    // 设置服务端IP地址
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 将serverAddr设置的信息与serverSock绑定
    if (bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        puts("bind() error");
        exit(EXIT_FAILURE);
    }

    // 监听该端口号，最大连接数为5
    if (listen(serverSock, 5) == -1)
    {
        puts("listen() error");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        socklen_t sockLength = sizeof(clientAddr);
        // 接收来自客户端的请求连接
        clientSock = accept(serverSock, (struct sockaddr *)&clientAddr, &sockLength);
        if (-1 == clientSock)
        {
            puts("accept() error");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("client connected\n");
        }
        int length = 0;
        char message[BUF_SIZE] = "\0";
        // 获取客户端发来的消息
        while ((length = read(clientSock, message, BUF_SIZE)) != 0)
        {
            // 向客户端发送消息
            write(clientSock, message, length);
            printf("[client] : %s\n", message);
        }
        // 关闭客户端套接字
        close(clientSock);
    }
    // 关闭服务端套接字
    close(serverSock);

    return 0;
}
