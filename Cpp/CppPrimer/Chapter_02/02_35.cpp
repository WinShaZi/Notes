#include <iostream>
#include <iomanip>

int main()
{
	const int i = 42;
	auto j = i;
	const auto &k = i;
	auto *p = &i;
	const auto j2 = i, &k2 = i;

	std::cout << setiosflags(std::ios::right);
	std::cout << " i : " << std::setw(2) << i << "    j : " << std::setw(2) << j << std::endl;
	std::cout << " k : " << std::setw(2) << k << "   *p : " << std::setw(2) << *p << std::endl;
	std::cout << "j2 : " << std::setw(2) << j2 << "   k2 : " << std::setw(2) << k2 << std::endl;
	std::cout << resetiosflags(std::ios::right);


	system("pause");
	return 0;
}