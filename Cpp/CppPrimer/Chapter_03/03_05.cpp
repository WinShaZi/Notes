#include <iostream>
#include <string>

int main()
{
	std::string str;

	std::cout  << "Input : " << std::endl;
	while (std::cin >> str)
		std::cout << str << ' ';

	system("pause");
	return 0;
}