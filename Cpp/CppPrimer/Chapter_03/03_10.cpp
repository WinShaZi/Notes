#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string str;
	char ch;

	while (std::cin.get(ch))
		if (!ispunct(ch))
			str += ch;
	std::cout << str << std::endl;    

	system("pause");
	return 0;
}