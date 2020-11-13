#include <iostream>

// 允许用户去保证一个函数或对象的构造函数是一个编译期常量
constexpr int GetValue()
{
    return 10;

    // return rand();  // error
}

int main(int argc, char const *argv[])
{
    char str[GetValue()] = {'\0'};

    /**
     * 输出
     * 10
     */
    std::cout << sizeof(str) << std::endl;

    return 0;
}
