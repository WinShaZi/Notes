#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    int serverSock = 0;
    struct sockaddr_in serverAddr;

    serverSock = socket(PF_INET, SOCK_DGRAM, 0);

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        puts("bind() error");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        struct sockaddr_in clientAddr;
        memset(&clientAddr, 0, sizeof(clientAddr));
        socklen_t clientAddrSize = sizeof(clientAddr);

        char message[BUF_SIZE] = "\0";
        // sendto,recvfrom一般用于UDP，当UDP进行connect()之后也可以使用send，recv
        int length = recvfrom(serverSock, message, BUF_SIZE, 0, (struct sockaddr *)&clientAddr, &clientAddrSize);
        printf("[client] : %s\n", message);
        sendto(serverSock, message, length, 0, (struct sockaddr *)&clientAddr, clientAddrSize);
    }
    close(serverSock);

    return 0;
}
