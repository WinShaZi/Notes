/**
 * 创建新进程，子进程从fork()函数饭后后开始执行
 * 父进程fork()返回非0，子进程返回0
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int globalValue = 10;
int main(int argc, char const *argv[])
{
    int localValue = 20;

    __pid_t pid = fork();
    if (0 == pid)
    {
        globalValue += 2;
        localValue += 2;
    }
    else
    {
        globalValue -= 2;
        localValue -= 2;
    }

    if (0 == pid)
    {
        printf("Children process : %d %d\n", globalValue, localValue);
    }
    else
    {
        printf("Parent process : %d %d\n", globalValue, localValue);
    }

    return 0;
}
