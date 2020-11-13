#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string str = R"(
    Hello
    World!
    )";

    /**
     * 输出
     * 
     *     Hello
     *     World!
     * 
     */
    std::cout << str << std::endl;

    return 0;
}
