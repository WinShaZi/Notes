/**
 * 双向管道 
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    int fds[2] = {0};

    char msg1[BUF_SIZE] = "Father";
    char msg2[BUF_SIZE] = "Child";
    char buf[BUF_SIZE] = "\0";

    pipe(fds);
    __pid_t pid = fork();
    if (0 == pid)
    {
        write(fds[1], msg2, BUF_SIZE);
        sleep(1);
        read(fds[0], buf, BUF_SIZE);
        printf("[Father] : %s\n", buf);
    }
    else
    {
        read(fds[0], buf, BUF_SIZE);
        printf("[Child] : %s\n", buf);
        sleep(1);
        write(fds[1], msg1, BUF_SIZE);
    }

    return 0;
}
