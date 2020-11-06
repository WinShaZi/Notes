#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    std::string str = "Hello World!";

    for (const auto &c : arr)
    {
        std::cout << c;
    }
    std::cout << std::endl;

    for (const auto &c : str)
    {
        std::cout << c;
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}
