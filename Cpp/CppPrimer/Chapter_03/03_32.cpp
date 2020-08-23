#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ia(10), ib;

    for (size_t ix = 0; ix < 10; ++ix)
        ia[ix] = ix;
	ib = ia;
	for (auto n : ib)
		std::cout << n << ' ';

    system("pause");
    return 0; 
}