#include <stdio.h>
#include <stdalign.h>
#include <stdlib.h>

struct S1
{
    int i;
    double d;
    char c;
};

// 指定对齐字节长度
struct S2
{
    alignas(16) int i;
    alignas(16) double d;
    alignas(16) char c;
};

int main()
{
    printf("S1 alignof : %ld  S1 sizeof : %ld\n", alignof(struct S1), sizeof(struct S1));
    printf("S2 alignof : %ld  S2 sizeof : %ld\n", alignof(struct S2), sizeof(struct S2));

    int *p1 = malloc(1024 * sizeof(int));
    printf("default-aligned addr:   %p\n", (void *)p1);
    free(p1);

    /**
     * 参数一指定对齐字节，参数二必须是参数一的整数倍
     * 申请失败返回NULL
     */
    int *p2 = aligned_alloc(1024, 1024 * sizeof(int));
    printf("1024-byte aligned addr: %p\n", (void *)p2);
    free(p2);

    return 0;
}
