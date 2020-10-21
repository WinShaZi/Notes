/**
 * 接受一次数据则注册一次事件
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

#define BUF_SIZE 256
#define EPOLL_SIZE 50

int main(int argc, char const *argv[])
{
    int serverSock = 0;
    int clientSock = 0;

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;


    serverSock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&serverAddr, 0, sizeof(serverAddr));
    memset(&clientAddr, 0, sizeof(clientAddr));

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

    int epollFd = epoll_create(EPOLL_SIZE);

    struct epoll_event *epollEvents = calloc(EPOLL_SIZE, sizeof(struct epoll_event));

    struct epoll_event event;
    memset(&event, 0, sizeof(event));
    event.events = EPOLLIN;
    event.data.fd = serverSock;

    epoll_ctl(epollFd, EPOLL_CTL_ADD, serverSock, &event);

    while (1)
    {
        int clientEvent = epoll_wait(epollFd, epollEvents, EPOLL_SIZE, -1);
        if (-1 == clientEvent)
        {
            puts("epoll_wait() error");
            break;
        }

        for (int i = 0; i < clientEvent; i++)
        {
            int tempEpFd = epollEvents[i].data.fd;

            if (tempEpFd == serverSock)
            {
                socklen_t addrLength = sizeof(clientAddr);
                clientSock = accept(serverSock, (struct sockaddr *)&clientAddr, &addrLength);
                event.events = EPOLLIN;     // 设置为条件触发
                event.data.fd = clientSock;
                epoll_ctl(epollFd, EPOLL_CTL_ADD, clientSock, &event);
                printf("Connected client : %d\n", clientSock);
            }
            else
            {
                char buf[BUF_SIZE] = "\0";
                int length = read(tempEpFd, buf, BUF_SIZE);
                if (length > 0)
                {
                    write(tempEpFd, buf, length);
                    printf("[client] : %s\n", buf);
                }
                else
                {
                    epoll_ctl(epollFd, EPOLL_CTL_DEL, tempEpFd, NULL);
                    close(tempEpFd);
                    printf("Closed client : %d\n", tempEpFd);
                }
            }
        }
    }
    close(serverSock);
    close(epollFd);

    return 0;
}
