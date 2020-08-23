#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec(10, 100);

	std::cout << "a : " << *vec.begin() << std::endl;
	std::cout << "b : " << *vec.begin() + 1 << std::endl;

    std::cout << "a : " << *(vec.begin()) << std::endl;
	std::cout << "b : " << *(vec.begin()) + 1 << std::endl;

    system("pause");
    return 0;
}