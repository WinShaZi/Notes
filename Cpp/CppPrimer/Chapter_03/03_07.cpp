#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string str = "abcdefghijklmnopqrstuvwxyz";
	
	std::cout << str << std::endl;
	for (char ch : str) //for (auto &ch : str)
		ch = toupper(ch);
	std::cout << str << std::endl;

	system("pause");
	return 0;
}