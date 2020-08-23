#include <iostream>
#include <cstring>
#include <string>

int main()
{
	const char *s1 = "hello";
	const char *s2 = "Hello";
	const std::string st1 = "hello";
	const std::string st2 = "Hello";

	if (strcmp(s1, s2) == 0)
		std::cout << "Same" << std::endl;
	else
	{
		std::cout << (strcmp(s1, s2) < 0 ? "s1 < s2" : "s1 > s2") << std::endl;
	}

	if (st1 == st2)
		std::cout << "Same" << std::endl;
	else
	{
		std::cout << (st1 < st2 ? "s1 < s2" : "s1 > s2") << std::endl;
	}
	
 	
    system("pause");
    return 0; 
}