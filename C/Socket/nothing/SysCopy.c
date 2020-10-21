#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    int fd1 = 0;
    int fd2 = 0;

    char buf[BUF_SIZE] = "\0";

    fd1 = open("data.txt", O_RDONLY);
    fd2 = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC);

    int length = 0;
    while ((length = read(fd1, buf, sizeof(buf))) > 0)
    {
        write(fd2, buf, length);
    }

    close(fd1);
    close(fd2);

    return 0;
}
