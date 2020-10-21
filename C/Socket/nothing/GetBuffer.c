#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{
    int sockTcp = 0;
    int sockUdp = 0;
    int sendBuf = 0;
    int receiveBuf = 0;
    socklen_t sockLength = sizeof(sendBuf);

    sockTcp = socket(PF_INET, SOCK_STREAM, 0);
    sockUdp = socket(PF_INET, SOCK_DGRAM, 0);

    printf("SOCK_STREAM : %d\n", sockTcp);
    printf("SOCK_DGRAM : %d\n", sockUdp);

    // 获取发送区大小
    if (getsockopt(sockTcp, SOL_SOCKET, SO_SNDBUF, (void *)&sendBuf, &sockLength) != 0)
    {
        puts("getsockopt() error");
    }
    else
    {
        printf("Send buffer: %d\n", sendBuf);
    }

    // 获取接收区大小
    if (getsockopt(sockUdp, SOL_SOCKET, SO_RCVBUF, (void *)&receiveBuf, &sockLength) != 0)
    {
        puts("getsockopt() error");
    }
    else
    {
        printf("Receive buffer : %d\n", receiveBuf);
    }

    return 0;
}