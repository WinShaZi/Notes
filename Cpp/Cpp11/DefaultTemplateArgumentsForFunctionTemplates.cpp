#include <iostream>

template <typename T = int>
T Func(const T &t)
{
    return t;
}

int main(int argc, char const *argv[])
{
    std::cout << Func(1) << std::endl;
    std::cout << Func<>(9.9) << std::endl;
    std::cout << Func<std::string>("Hello World!") << std::endl;

    return 0;
}
