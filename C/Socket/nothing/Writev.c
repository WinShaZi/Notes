#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>

int main(int argc, char const *argv[])
{
    // 储存信息及长度
    struct iovec vec[2];
    
    char buf1[] = "1234567";
    char buf2[] = "7654321";

    vec[0].iov_base = buf1;
    vec[0].iov_len = sizeof(buf1);
    vec[1].iov_base = buf2;
    vec[1].iov_len = 3;

    writev(1, vec, 2);  // 1:向控制台输出

    return 0;
}
