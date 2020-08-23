#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string str = "abcdefghijklmnopqrstuvwxyz";
	
	std::cout << str << std::endl;          //auto n = 0;
	for (auto n = 0; n < str.size(); n++)   //while (n < str.size())
		str[n] = toupper(str[n]);           //    str[n] = toupper(str[n]);
	std::cout << str << std::endl;          

	system("pause");
	return 0;
}