#include <iostream>
#include <iterator>
#include <vector>

int main()
{
	int num[]  = { 1, 3, 5, 7, 9 };
	std::vector<int> vi(std::begin(num), std::end(num));

	for (auto n : vi)
		std::cout << n << std::endl;
 	
    system("pause");
    return 0; 
}