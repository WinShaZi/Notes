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

    serverSock = socket(PF_INET, SOCK_STREAM, 0);

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
            puts("accept() error");
            exit(EXIT_FAILURE);
        }
        else
        {
            fputs("Client connected\n", stdout);
        }
        int length = 0;
        char message[BUF_SIZE] = "\0";
        while ((length = read(clientSock, message, BUF_SIZE)) != 0)
        {
            write(clientSock, message, length);
            printf("[client] : %s\n", message);
        }
        close(clientSock);
    }
    close(serverSock);

    return 0;
}
