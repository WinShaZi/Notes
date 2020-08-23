#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::vector<int> vi;
	int i;

	while (std::cin >> i)
		vi.push_back(i);
	for (auto pd1 = vi.begin(), pd2 = vi.end() - 1; pd1 <= pd2; pd1++, pd2--)
		std::cout << *pd1 << " + " << *pd2 << " = " << *pd1 + *pd2 << std::endl;

	system("pause");
	return 0;
}