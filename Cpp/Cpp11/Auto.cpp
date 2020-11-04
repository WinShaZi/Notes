#include <iostream>

int main(int argc, char const *argv[])
{
    // auto 依据右值的类型对左值进行推导，直接推导其原始类型

    int i = 1;
    int *pi = &i;
    int &li = i;
    int &&ri = i + i;
    const int c_i = i;
    const int *c_pi = &i;
    int *const c_ip = &i;
    const int &c_li = i;
    const int &&c_ri = i + i;

    {
        // int
        auto value = i;
    }
    {
        // int *
        auto value = pi;
    }
    {
        // int
        auto value = li;
    }
    {
        // int
        auto value = ri;
    }
    {
        // int
        auto value = c_i;
    }
    {
        // const int *
        auto value = c_pi;
    }
    {
        // int *
        auto value = c_ip;
    }
    {
        // int
        auto value = c_li;
    }
    {
        // int
        auto value = c_ri;
    }

    return 0;
}
