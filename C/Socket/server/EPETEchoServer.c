
/**
 * 边缘触发，无论缓冲区内是否有剩余未读取的数据，都只注册一次事件 
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <errno.h>
#include <fcntl.h>

#define BUF_SIZE 256
#define EPOLL_SIZE 50

//设置套接字非阻塞
void SetNonblockingMode(int fd);

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

    SetNonblockingMode(serverSock);

    struct epoll_event event;
    memset(&event, 0, sizeof(event));
    event.events = EPOLLIN;
    event.data.fd = serverSock;

    epoll_ctl(epollFd, EPOLL_CTL_ADD, serverSock, &event);

    while (1)
    {
        int clientEvent = epoll_wait(epollFd, epollEvents, EPOLL_SIZE, -1);     // 等待事件的发生
        if (-1 == clientEvent)
        {
            puts("epoll_wait() error");
            break;
        }

        puts("Return epoll_wait");

        for (int i = 0; i < clientEvent; i++)
        {
            int tempEpFd = epollEvents[i].data.fd;

            if (tempEpFd == serverSock)
            {
                socklen_t addrLength = sizeof(clientAddr);
                clientSock = accept(serverSock, (struct sockaddr *)&clientAddr, &addrLength);
                SetNonblockingMode(clientSock);
                event.events = EPOLLIN | EPOLLET;       // 设置为边缘触发
                event.data.fd = clientSock;
                epoll_ctl(epollFd, EPOLL_CTL_ADD, clientSock, &event);      // 从监听中增加该套接字
                printf("Connected client : %d\n", clientSock);
            }
            else
            {
                char buf[BUF_SIZE] = "\0";
                int length = read(epollEvents[i].data.fd, buf, BUF_SIZE);
                if (length > 0)
                {
                    write(tempEpFd, buf, length);
                    printf("[client] : %s\n", buf);
                }
                else if (length == 0)
                {
                    epoll_ctl(epollFd, EPOLL_CTL_DEL, tempEpFd, NULL);      // 从监听中删除该套接字
                    close(tempEpFd);
                    printf("Closed client : %d\n", tempEpFd);
                }
                else
                {
                    if (errno == EAGAIN)
                    {
                        break;      // 标志已经读取了缓冲内全部的数据
                    }
                }
                
            }
        }
    }
    close(serverSock);
    close(epollFd);

    return 0;
}

void SetNonblockingMode(int fd)
{
    int flag = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flag | O_NONBLOCK);
}
