/**
 * 单向管道
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    int fds[2] = {0};

    pipe(fds);
    __pid_t pid = fork();
    if (0 == pid)
    {
        char message[] = "Hello World!";
        write(fds[1], message, sizeof(message));
    }
    else
    {
        char message[BUF_SIZE] = "\0";
        read(fds[0], message, sizeof(message));
        puts(message);
    }

    return 0;
}
