#include <iostream>
#include <string>
#include <vector>
#include <iterator>

int main()
{
	std::vector<int> v1;
	std::vector<int> v2(10);
	std::vector<int> v3(10, 42);
	std::vector<int> v4{10};
	std::vector<int> v5{ 10, 42 };
	std::vector<std::string> v6{10};
	std::vector<std::string> v7{ 10, "hi"};

	std::vector<std::vector<int>> vi{ v1, v2,v3,v4,v5 };

	for (auto n = 0; n < vi.size(); n++)
	{
		for(auto m : vi[n])
			std::cout << m << ' ';
		std::cout << "end" << std::endl;
	}

	std::vector<std::vector<std::string>> vs{ v6, v7 };

	for (auto n = vs.begin(); n < vs.end(); n++)
	{
		for(auto m : *n)
			std::cout << m << ' ';
		std::cout << "end" << std::endl;
	}

	system("pause");
	return 0;
}