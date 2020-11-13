#include <iostream>

unsigned long long operator""_K(const unsigned long long ull)
{
    return 1024 * ull;
}

int main(int argc, char const *argv[])
{
    /**
     * 输出
     * 102400
     */
    std::cout << 100_K << std::endl;

    return 0;
}
