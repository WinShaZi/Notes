#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vi{ 1, 3, 5, 7, 9 };
	int num[5] = {};
	int i = 0;

	for (auto n : vi)
	{
		num[i] = n;
		std::cout << num[i] << std::endl;
		i++;
	}
    system("pause");
    return 0; 
}