#include <iostream>

// 默认类型为int
enum class Color
{
    RED = 1,
    YELLOW = 2,
    BLUE = 3
};

enum class Number : unsigned int
{
    ZERO,
    ONE,
    TWO
};

int main(int argc, char const *argv[])
{
    Color c = Color::RED;
    // Number n = 0;   // error
    // Number n = Color::RED;  // error

    return 0;
}
