#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int sockTcp = 0;

    int sendBuf = 0;
    int receiveBuf = 0;
    socklen_t sockLength = sizeof(sendBuf);

    sockTcp = socket(PF_INET, SOCK_STREAM, 0);

    printf("SOCK_STREAM : %d\n", sockTcp);

    if (getsockopt(sockTcp, SOL_SOCKET, SO_SNDBUF, (void *)&sendBuf, &sockLength) != 0)
    {
        puts("getsockopt() error");
    }
    else
    {
        printf("Send buffer: %d\n", sendBuf);
    }

    if (getsockopt(sockTcp, SOL_SOCKET, SO_RCVBUF, (void *)&receiveBuf, &sockLength) != 0)
    {
        puts("getsockopt() error");
    }
    else
    {
        printf("Receive buffer : %d\n", receiveBuf);
    }

    sendBuf = pow(2, 16);
    receiveBuf = pow(2, 16);

    // 设置接收及发送区大小
    if (setsockopt(sockTcp, SOL_SOCKET, SO_SNDBUF, (void *)&sendBuf, sockLength) != 0)
    {
        puts("setsockopt() error");
    }
    if (setsockopt(sockTcp, SOL_SOCKET, SO_RCVBUF, (void *)&receiveBuf, sockLength) != 0)
    {
        puts("setsockopt() error");
    }

    if (getsockopt(sockTcp, SOL_SOCKET, SO_SNDBUF, (void *)&sendBuf, &sockLength) != 0)
    {
        puts("getsockopt() error");
    }
    else
    {
        printf("Send buffer: %d\n", sendBuf);
    }

    if (getsockopt(sockTcp, SOL_SOCKET, SO_RCVBUF, (void *)&receiveBuf, &sockLength) != 0)
    {
        puts("getsockopt() error");
    }
    else
    {
        printf("Receive buffer : %d\n", receiveBuf);
    }

    return 0;
}