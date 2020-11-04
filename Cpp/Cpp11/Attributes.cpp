#include <iostream>

[[noreturn]] void Func()
{
    exit(0);
}

int main(int argc, char const *argv[])
{
    Func();

    return 0;
}
