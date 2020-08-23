#include <iostream>

int main()
{
    std::cout << unsigned('q') << std::endl;
    std::cout << ~'q' << std::endl;
    std::cout << (~'q' << 6) << std::endl;

    system("pause");
    return 0;
}