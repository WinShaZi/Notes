#include <iostream>
#include <cstring>

int main()
{
	const char s1[] = "Hello ";
	const char s2[] = "World!";
	char s3[strlen(s1) + strlen(s2) + 1];

	strcpy(s3, s1);
	strcat(s3, s2);

	std::cout << s3 << std::endl;
 	
    system("pause");
    return 0; 
}