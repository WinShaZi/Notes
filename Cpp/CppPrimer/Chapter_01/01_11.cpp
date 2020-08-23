#include <iostream>

int main()
{
	int m, n;

	std::cout << "Input two number (a < b): " << std::endl;
	std::cin >> m >> n;
	while (n >= m)
	{
		std::cout << m++ << std::endl;
	}

	system("pause");
	return 0; 
 }