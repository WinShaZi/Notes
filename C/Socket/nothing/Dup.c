#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int cfd1 = 0;
    int cfd2 = 0;

    char str1[] = "Hello\n";
    char str2[] = "World\n";

    // 拷贝文件描述符
    cfd1 = dup(1);          // 拷贝控制台输出描述符
    // 同上，可以指定文件描述符，若指定的文件描述符已打开，则会将其关闭
    cfd2 = dup2(cfd1, 7);

    printf("fd1 = %d\t fd2 = %d\n", cfd1, cfd2);
    write(cfd1, str1, sizeof(str1));
    write(cfd2, str2, sizeof(str2));

    close(cfd1);
    close(cfd2);

    write(1, str1, sizeof(str1));
    close(1);
    write(1, str2, sizeof(str2));

    return 0;
}
