#include <iostream>
#include <string>

int main()
{
	std::string str1, str2;

	std::cout  << "Input two strings : " << std::endl;
	std::cin >> str1 >> str2;
	if (str1 == str2)
		std::cout << str1 << std::endl;
	else
		std::cout << ((str1 > str2) ? str1 : str2) << std::endl;

	system("pause");
	return 0;
}