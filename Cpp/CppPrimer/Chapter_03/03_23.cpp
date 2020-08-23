#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::vector<int> vi(10, 150);

	for (auto pd = vi.begin(); pd != vi.end(); pd++)
		*pd *= 2;
	for (auto n : vi)
		std::cout << n << ' ';
	std::cout << "end" << std::endl; 

	system("pause");
	return 0;
}