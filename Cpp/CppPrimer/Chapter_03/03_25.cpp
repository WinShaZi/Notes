#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::vector<unsigned> scores(11, 0);
	unsigned grade;

	while (std::cin >> grade)
	{
		if (grade <= 100)
			++*(scores.begin() + grade / 10);
	}

	for (auto n : scores)
		std::cout << n << ' ';
	std::cout << "end" << std::endl;

	system("pause");
	return 0;
}