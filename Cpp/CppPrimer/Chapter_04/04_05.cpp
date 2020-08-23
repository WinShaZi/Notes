#include <iostream>

int main()
{
	std::cout << -30 * 3 + 21 / 5 << std::endl;
	std::cout << -30 + 3 * 21 / 5 << std::endl;
	std::cout << -30 / 3 * 21 % 5 << std::endl;
	std::cout << -30 / 3 * 21 % 4 << std::endl;

    system("pause");
    return 0;
}