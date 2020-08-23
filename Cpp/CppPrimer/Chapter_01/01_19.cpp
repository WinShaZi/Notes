#include <iostream>

int main()
{
	int m, n;

	std::cout << "Input two number (a < b): " << std::endl;
	while (!(std::cin >> m >> n) || m >= n)
	{
		std::cin.clear();
		while(std::cin.get() != '\n');
		std::cout << "Input two number (a < b): " << std::endl;
	}
	while (n >= m)
	{
		std::cout << m++ << std::endl;
	}

	system("pause");
	return 0; 
 }