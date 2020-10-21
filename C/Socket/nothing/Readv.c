#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    // 储存信息及长度
    struct iovec vec[2];

    char buf1[BUF_SIZE] = "\0";
    char buf2[BUF_SIZE] = "\0";

    vec[0].iov_base = buf1;
    vec[0].iov_len = 5;
    vec[1].iov_base = buf2;
    vec[1].iov_len = BUF_SIZE;

    readv(0, vec, 2);       // 0:表示控制台输入
    printf("%s %s\n", buf1, buf2);

    return 0;
}
