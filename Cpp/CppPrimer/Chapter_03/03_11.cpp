#include <iostream>
#include <string>

int main()
{
	const std::string s = "Keep out";

	for (auto &c : s)
		std::cout << c << ' ';

	system("pause");
	return 0;
}

//合法，const char &c;