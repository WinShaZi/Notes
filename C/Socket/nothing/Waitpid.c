/**
 * waitpid()不会阻塞
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
        sleep(3);
        return 3;
    }
    else
    {
        while (!waitpid(-1, &status, WNOHANG))
        {
            sleep(1);
            puts("sleep 1 Sec");
        }

        if (WIFEXITED(status))
        {
            printf("Child send %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
