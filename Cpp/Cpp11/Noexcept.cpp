#include <iostream>

// 该函数不允许抛出异常，抛出异常则直接终结
void foo() noexcept
{
    throw;
    std::cout << "foo()" << std::endl;
}

// 当表达式为真则该函数不允许抛出异常，抛出异常则直接终结
void bar() noexcept(sizeof(int) == 4)
{
    throw;
    std::cout << "bar()" << std::endl;
}

int main(int argc, char const *argv[])
{

    return 0;
}
