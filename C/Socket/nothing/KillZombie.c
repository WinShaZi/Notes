/**
 * 找不到sigaction的定义
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <asm/signal.h>
#include <sys/wait.h>

void ChildProcess(int sig)
{
    // 杀死僵尸进程
    int status = 0;
    __pid_t id = waitpid(-1, &status, WNOHANG);
    if(WIFEXITED(status))
    {
        printf("Child ID : %d\n", id);
        printf("Child send : %d\n", WEXITSTATUS(status));
    }
}

int main(int argc, char const *argv[])
{
    struct sigaction act;
    act.sa_handler = ChildProcess;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGCHLD, &act, 0);

    __pid_t pid = fork();
    if (0 == pid)
    {
        puts("Hi! I'm child process");
        sleep(3);
        return 12;
    }
    else
    {
        printf("Child ID : %d\n", pid);
        pid = fork();
        if (0 == pid)
        {
            puts("Hi! I'm child process");
            sleep(3);
            exit(24);
        }
        else
        {
            printf("Child ID : %d\n", pid);
            for (int i = 0; i < 3; i++)
            {
                puts("wait...");
                sleep(5);
            }
                }
    }

    return 0;
}
