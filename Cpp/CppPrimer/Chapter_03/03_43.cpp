#include <iostream>
#include <iterator>

int main()
{
	int ia[3][4] = {
		{ 0, 1, 2, 3 },
		{ 4, 5, 6, 7 },
		{ 8, 9, 10, 11 }
	};

	for (int (&n)[4] : ia)
		for (int m : n)
			std::cout << m << ' ';
	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
		for(int j = 0; j < 4; j++)
			std::cout << ia[i][j] << ' ';
	std::cout << std::endl;

	for (int (*pi)[4] = std::begin(ia); pi != std::end(ia); pi++)
		for (int *pj = std::begin(*pi); pj != std::end(*pi); pj++)
			std::cout << *pj << ' ';
	std::cout << std::endl;

    system("pause");
    return 0; 
}