#include <iostream>
#include <vector>

int main()
{
	const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
	const char *cp = ca;

	while (*cp)
	{
		std::cout << *cp << std::endl;
		++cp;
	}
	
    system("pause");
    return 0; 
}