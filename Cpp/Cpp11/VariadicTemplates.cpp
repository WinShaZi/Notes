#include <iostream>

// 此函数作为终止函数
void print()
{
}

template <typename T, typename... Args>
void print(const T &t, const Args &... args)
{
    // sizeof...(args); // 获取可变的个数
    std::cout << t;
    print(args...);
}

int main()
{
    print("hello", ' ', "World", '!', '\n');

    return 0;
}
