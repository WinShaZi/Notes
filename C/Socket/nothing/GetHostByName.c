#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char const *argv[])
{
    // 同过域名获取host信息
    struct hostent *host = gethostbyname("www.baidu.com");

    if (NULL == host)
    {
        puts("gethostbyname() error");
        exit(EXIT_FAILURE);
    }

    printf("Official name : %s\n", host->h_name);
    for (int i = 0; host->h_aliases[i] != NULL; i++)
    {
        printf("Aliases %d : %s\n", i + i, host->h_aliases[i]);
    }
    printf("Address type : %s\n", (host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6");
    for (int i = 0; host->h_addr_list[i] != NULL; i++)
    {
        printf("IP address %d : %s\n", i + 1, inet_ntoa(*(struct in_addr *) host->h_addr_list[i]));
    }

    return 0;
}
