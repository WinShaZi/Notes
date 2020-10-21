#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void TimeOut(int sig)
{
    if (SIGALRM == sig)
    {
        puts("Time out");
    }
    alarm(2);
}

void KeyControl(int sig)
{
    if (SIGINT == sig)
    {
        puts("CTRL+C pressed");
    }
}

int main(int argc, char const *argv[])
{
    // 设置超时信号
    signal(SIGALRM, TimeOut);
    // 按下CTRL+C则触发信号
    signal(SIGINT, KeyControl);
    alarm(2);

    for (int i = 0; i < 3; i++)
    {
        puts("wait...");
        sleep(100);
    }

    return 0;
}
