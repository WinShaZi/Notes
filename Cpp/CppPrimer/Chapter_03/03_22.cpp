#include <iostream>
#include <string>
#include <vector>
#include <iterator>

int main()
{
	std::vector<std::string> vs;
	std::string st;

    while (getline(std::cin, st))
		vs.push_back(st);
	for (auto pd = vs.begin(); pd != vs.end() && !pd->empty(); pd++)
	{
		for (auto &c : *pd)
			c = toupper(c);
		std::cout << *pd << std::endl;
	}

	system("pause");
	return 0;
}