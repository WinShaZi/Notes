#include <iostream>

int main()
{
	int num;
	int count = 0;

	while (std::cin >> num)
		count += num;
	std::cout << count << std::endl;

	system("pause");
	return 0; 
 }