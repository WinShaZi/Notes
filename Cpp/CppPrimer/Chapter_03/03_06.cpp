#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string str = "abcdefghijklmnopqrstuvwxyz";
	
	std::cout << str << std::endl;
	for (auto &ch : str)
		ch = 'X';
	std::cout << str << std::endl;

	system("pause");
	return 0;
}