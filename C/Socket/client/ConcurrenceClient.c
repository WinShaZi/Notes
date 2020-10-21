#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdbool.h>

#define BUF_SIZE 256

void ReadRoutine(int sock, char * message)
{
    while (1)
    {
        int length = read(sock, message, BUF_SIZE);
        if (0 == length)
        {
            puts("Server disconnected");
            return;
        }
        message[length] = 0;
        printf("[server] : %s\n", message);
    }
}

void WriteRoutine(int sock, char * message)
{
    while (1)
    {
        scanf("%s", message);
        if (strcmp(message, "q") == 0 || strcmp(message, "Q") == 0)
        {
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
    if(0 == pid)
    {
        WriteRoutine(clientSock, message);
    }
    else
    {
        ReadRoutine(clientSock, message);
    }

    return 0;
}
