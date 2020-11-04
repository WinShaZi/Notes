#include <iostream>

enum Color : int;
enum class Number;

enum Color : int
{
    RED,
    YELLOW,
    BLUE
};

enum class Number
{
    ZERO,
    ONE,
    TWO
};

int main(int argc, char const *argv[])
{
    std::cout << RED << std::endl;
    std::cout << int(Number::ZERO) << std::endl;

    return 0;
}
