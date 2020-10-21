#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    int clinetSock = 0;
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));

    clinetSock = socket(PF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    while (1)
    {
        char message[BUF_SIZE] = "\0";
        printf("Insert message(q to quit) : ");
        scanf("%s", message);
        if(strcmp(message, "q") == 0 || strcmp(message, "Q") == 0)
        {
            puts("Break!");
            break;
        }
        // sendto,recvfrom一般用于UDP，当UDP进行connect()之后也可以使用send,recv
        sendto(clinetSock, message, BUF_SIZE, 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

        struct sockaddr_in serverSockAddr;
        memset(&serverSockAddr, 0, sizeof(serverSockAddr));
        socklen_t serverSockSize = sizeof(serverSockAddr);

        int length = recvfrom(clinetSock, message, BUF_SIZE, 0, (struct sockaddr *)&serverSockAddr, &serverSockSize);

        message[length] = 0;

        printf("[server] : %s\n", message);
    }
    close(clinetSock);

    return 0;
}
