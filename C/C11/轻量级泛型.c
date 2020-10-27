#include <stdio.h>

// 支持轻量级泛型编程，依据参数不同的类型执行不同的操作，语法类似于switch
#define GetTypeName(var) _Generic((var), char \
                                  : "char",   \
                                    int       \
                                  : "int",    \
                                    double    \
                                  : "double", \
                                    default   \
                                  : "none")

int main()
{
    printf("char typename           : %s\n", GetTypeName((char)0));
    printf("int typename            : %s\n", GetTypeName((int)0));
    printf("double typename         : %s\n", GetTypeName((double)0));
    printf("unsigned int typename   : %s\n", GetTypeName((unsigned int)0));

    return 0;
}