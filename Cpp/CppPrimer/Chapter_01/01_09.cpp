#include <iostream>

int main()
{
	int n = 50;
	int count = 0;

	while (n <= 100)
	{
		count += n;
		n++;
	}
	std::cout << count << std::endl;

	system("pause");
	return 0; 
 }