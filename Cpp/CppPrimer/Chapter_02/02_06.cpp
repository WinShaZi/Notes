#include <iostream>

int main()
{
	int month = 9;
	int year = 7;

	std::cout << month << std::endl;
	std::cout << year << std::endl;

	month = 0x09;
	year = 07;
	std::cout << month << std::endl;
	std::cout << year << std::endl;

	system("pause");
	return 0; 
 }