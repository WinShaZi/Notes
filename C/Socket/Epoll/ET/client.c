#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    int clientSock = 0;

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));

    clientSock = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == clientSock)
    {
        puts("socket() error");
        exit(EXIT_FAILURE);
    }

    // 设置服务端的IP地址和端口号
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 客户端clientSock连接服务端地址
    if (connect(clientSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        puts("connect() error");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        char message[BUF_SIZE] = "\0";
        printf("Input message(q to quit) : ");
        scanf("%s", message);
        if (strcmp(message, "q") == 0 || strcmp(message, "Q") == 0)
        {
            puts("break");
            exit(EXIT_FAILURE);
        }

        int writeLength = write(clientSock, message, strlen(message));

        int readLength = 0;
        // 循环接收服务端发送的数据，直至达到发送的数据长度
        while (readLength < writeLength)
        {
            int tempLength;
            tempLength = read(clientSock, message, BUF_SIZE - 1);
            if (-1 == tempLength)
            {
                puts("read() error");
                exit(EXIT_FAILURE);
            }
            readLength += tempLength;
        }
        message[readLength] = 0;
        printf("[server] : %s\n", message);
    }

    return 0;
}
