#include <iostream>

int main()
{
	std::cout << "/*" << std::endl;
	std::cout << "*/" << std::endl;
	std::cout << /* "*/" */" << std::endl;
	std::cout << /* "*/" /* "/*" */ << std::endl;

	system("pause");
	return 0; 
 }