#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;

    int fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if (-1 == fd)
    {
        fputs("File open error", stderr);
        exit(EXIT_FAILURE);
    }

    // 将流描述符转换成文件描述符
    fp = fdopen(fd, "w");
    fputs("Network C programming\n", fp);

    printf("File descriptor : %d\n", fileno(fp));

    fclose(fp);

    return 0;
}
