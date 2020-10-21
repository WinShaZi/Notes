#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    fd_set reads;

    FD_ZERO(&reads);
    FD_SET(0, &reads);      // 为控制台输入注册事件

    while (1)
    {
        fd_set temps = reads;
        struct timeval timeout = {3, 0};
        // 3秒内未接收到输入则为超时
        int result = select(1, &temps, 0, 0, &timeout); // 第一位参数表示最大范围
        if (-1 == result)
        {
            puts("select() error");
            break;
        }
        else if (0 == result)
        {
            puts("Time-out");
        }
        else
        {
            char message[BUF_SIZE] = "\0";
            int length = read(0, message, BUF_SIZE);
            message[BUF_SIZE] = 0;
            printf("[console] : %s\n", message);
        }
    }

    return 0;
}
