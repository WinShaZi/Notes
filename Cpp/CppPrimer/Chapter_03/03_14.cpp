#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vi;
	int n;

	while (std::cin >> n)
		vi.push_back(n);
	for (auto i : vi)
		std::cout << i << ' ';

	system("pause");
	return 0;
}