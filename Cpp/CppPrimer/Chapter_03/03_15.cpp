#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> vs;
	std::string st;

	while (std::cin >> st)
		vs.push_back(st);
	for (auto i : vs)
		std::cout << i << std::endl;

	system("pause");
	return 0;
}