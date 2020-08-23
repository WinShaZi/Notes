#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <new>
#include <cstring>

using namespace std;

int main()
{
	int *pa = new int[10]();
	
	delete[] pa;

	system("pause");
	return 0;
}