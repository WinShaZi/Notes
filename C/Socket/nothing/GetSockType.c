#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{
    int sockTcp = 0;
    int sockUdp = 0;
    int sockType = 0;
    socklen_t sockLength = sizeof(sockType);

    sockTcp = socket(PF_INET, SOCK_STREAM, 0);
    sockUdp = socket(PF_INET, SOCK_DGRAM, 0);

    printf("SOCK_STREAM : %d\n", sockTcp);
    printf("SOCK_DGRAM : %d\n", sockUdp);

    if (getsockopt(sockTcp, SOL_SOCKET, SO_TYPE, (void *)&sockType, &sockLength) != 0)
    {
        puts("getsockopt() error");
    }
    else
    {
        printf("Socket type TCP : %d\n", sockType);
    }

    if (getsockopt(sockUdp, SOL_SOCKET, SO_TYPE, (void *)&sockType, &sockLength) != 0)
    {
        puts("getsockopt() error");
    }
    else
    {
        printf("Socket type UDP : %d\n", sockType);
    }

    return 0;
}
