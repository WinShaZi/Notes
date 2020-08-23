#include <iostream>

int main()
{
	int a = 4, b = 3, c = 2, d = 1;

	std::cout << ((d < c && c < b && b < a) ? "true" : "false") << std::endl;

    system("pause");
    return 0;
}