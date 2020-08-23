#include <iostream>

int main()
{
	int num = 1;
	int *pt = &num;

	std::cout << num << std::endl;
	std::cout << ++*pt << std::endl;
	std::cout << ++num << std::endl; 

	system("pause");
	return 0;
 }