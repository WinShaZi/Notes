#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec(10, 100);
    std::vector<int>::size_type cnt = ivec.size();

    for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;
    for (auto n : ivec)
        std::cout << n << ' ';

    system("pause");
    return 0;
}