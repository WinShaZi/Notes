#include <iostream>

template <typename T = int>
T Func(const T &t)
{
    return t;
}

int main(int argc, char const *argv[])
{
    /**
     * 输出
     * 1
     * 9.9
     * Hello World!
     */
    std::cout << Func(1) << std::endl;
    std::cout << Func<>(9.9) << std::endl;
    std::cout << Func<std::string>("Hello World!") << std::endl;

    return 0;
}
