#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    std::string str = "Hello World!";

    /**
     * 输出
     * 1 2 3 4 5
     */
    for (const auto &c : arr)
    {
        std::cout << c;
    }
    std::cout << std::endl;

    /**
     * 输出
     * Hello World!
     */
    for (const auto &c : str)
    {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}
