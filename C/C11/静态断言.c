#include <stdio.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    // 在编译期产生错误，并显示参数二的消息
    static_assert(sizeof(int *) == 4, "64bit");

    return 0;
}
