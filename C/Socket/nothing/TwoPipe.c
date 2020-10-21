#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    int fds1[2] = {0};
    int fds2[2] = {0};

    char msg1[BUF_SIZE] = "Father";
    char msg2[BUF_SIZE] = "Child";
    char buf[BUF_SIZE] = "\0";

    pipe(fds1);
    pipe(fds2);
    __pid_t pid = fork();
    if (0 == pid)
    {
        write(fds1[1], msg2, BUF_SIZE);
        read(fds2[0], buf, BUF_SIZE);
        printf("[Father] : %s\n", buf);
    }
    else
    {
        read(fds1[0], buf, BUF_SIZE);
        printf("[Child] : %s\n", buf);
        write(fds2[1], msg1, BUF_SIZE);
    }

    return 0;
}
