#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main()
{
	std::vector<std::string> vs;
	std::string st;

	while (std::cin >> st)
	{
		for (auto &c : st)
			c = toupper(c);
		vs.push_back(st);
	}
	for (auto s : vs)
		std::cout << s << std::endl;

	system("pause");
	return 0;
}