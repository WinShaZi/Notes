/**
 * wait()请求返回子进程的返回值
 * wait()若没有子进程终止则会阻塞
 * WIFEXITED()子进程是否正常终止
 * WEXITSTATUS()返回子进程的返回值
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int status = 0;
    __pid_t pid = fork();

    if (0 == pid)
    {
        return 3;
    }
    else
    {
        printf("Child PID : %d\n", pid);
        pid = fork();
        if (0 == pid)
        {
            exit(7);
        }
        else
        {
            printf("Child PID : %d\n", pid);
            wait(&status);
            if (WIFEXITED(status))
            {
                printf("Child send one : %d\n", WEXITSTATUS(status));
            }

            wait(&status);
            if (WIFEXITED(status))
            {
                printf("Child send two : %d\n", WEXITSTATUS(status));
            }
            sleep(3);
        }
    }

    return 0;
}
