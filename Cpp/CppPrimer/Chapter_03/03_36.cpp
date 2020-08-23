#include <iostream>
#include <vector>

int main()
{
	int num1[] = { 1, 3, 5, 7, 9 };
	int num2[] = { 1, 3, 5, 7, 9 };

	if (sizeof(num1) == sizeof(num2))
	{
		for (int i = 0; i < sizeof(num1) / sizeof(int); i++)
		{
			if (num1[i] == num2[i])
				i++;
			else
				std::cout << "Differernt" << std::endl;
		}
		std::cout << "Same" << std::endl;
	}
	else
	{
		std::cout << "Differernt" << std::endl;
	}

	std::vector<int> v1{ 1, 3, 5, 7, 9 };
	std::vector<int> v2{ 1, 3, 5, 7, 9 };

	if (v1 == v2)
		std::cout << "Same" << std::endl;
	else
		std::cout << "Differernt" << std::endl;
	
    system("pause");
    return 0; 
}