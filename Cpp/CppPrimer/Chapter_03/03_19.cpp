#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1(10, 42);
    std::vector<int> v2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
    auto v3 = v1;

    auto vi = { v1, v2, v3 };

    for (auto n : vi)
    {
        for (auto m : n)
            std::cout << m << ' ';
        std::cout << "end" << std::endl;
    }

    system("pause");
    return 0;
}