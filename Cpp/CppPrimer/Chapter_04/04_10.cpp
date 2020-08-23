#include <iostream>

int main()
{
	int i;
	int sum = 0;

	while (std::cin >> i && i != 42)
		sum += i;

	std::cout << sum << std::endl;

    system("pause");
    return 0;
}