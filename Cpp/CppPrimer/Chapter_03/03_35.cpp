#include <iostream>
#include <iterator>

int main()
{
	int num[] = { 1, 3, 5, 7, 9 };

	for (int *pb = std::begin(num), *pe = std::end(num); pb != pe; pb++)
		*pb = 0;
	for (auto n : num)
		std::cout << n << ' ';

    system("pause");
    return 0; 
}