#include <iostream>

int main()
{
	short i = 32767;
	short j = -32768;
	unsigned k = 0;
	
	std::cout << (i += 1) << std::endl;
	std::cout << (j -= 1) << std::endl;
	std::cout << (k -= 1) << std::endl;

    system("pause");
    return 0;
}