#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // 以独占模式打开，当文件存在或者无法创建都会失败
    FILE *fp = fopen("data", "w+x");
    if (NULL == fp)
    {
        printf("open file failure\n");
        puts(strerror(errno));
    }
    else
    {
        printf("open file success\n");
        fclose(fp);
    }

    return 0;
}
