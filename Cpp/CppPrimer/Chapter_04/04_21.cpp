#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vi{ 1, 2, 3, 4, 5};

    for (auto &n : vi)
        std::cout << ((n % 2 == 0) ? n : 2 * n) << ' ';
    std::cout << std::endl;

    system("pause");
    return 0;
}