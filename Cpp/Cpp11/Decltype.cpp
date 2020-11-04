#include <iostream>

int main(int argc, char const *argv[])
{
    // decltype直接获取括号内的变量的类型

    int i = 1;
    int &li = i;
    int &&ri = i + i;
    const int c_i = i;
    const int *c_pi = &i;
    int *const c_ip = &i;

    {
        // int
        decltype(i) value;
    }
    {
        // int &
        decltype(li) value = i;
    }
    {
        // int &&
        decltype(ri) value = i + i;
    }
    {
        // const int
        decltype(c_i) value = i;
    }
    {
        // const int *
        decltype(c_pi) value = &i;
    }
    {
        // int *const
        decltype(c_ip) value = &i;
    }

    return 0;
}
