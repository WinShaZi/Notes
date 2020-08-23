#include <iostream>
#include <string>

int main()
{
	std::string str;

	std::cout << str[0] << std::endl;          

	system("pause");
	return 0;
}

//不合法，因为字符串S是一个空字符串，第一个元素是未知的，引用非法