#include <iostream>

template <typename T, typename U>
auto Func(T t, U u) -> decltype(t + u)
{
    return t + u;
}

int main(int argc, char const *argv[])
{
    /**
     * 输出
     * 2
     */
    std::cout << Func<int, double>(1, 1) << std::endl;

    return 0;
}
