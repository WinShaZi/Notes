#include <iostream>
#include <vector>

template <typename T>
using Vec = std::vector<T>;

using VecInt = std::vector<int>;

int main(int argc, char const *argv[])
{
    Vec<int> vi1 = {1, 2, 3};
    VecInt vi2 = vi1;

    for (size_t i = 0; i < vi2.size(); i++)
    {
        std::cout << vi2[i] << std::endl;
    }

    return 0;
}
