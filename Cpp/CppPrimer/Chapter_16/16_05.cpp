#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void print(const T& t)
{
	for (auto n : t)
		cout << n << endl;
}

int main()
{
	char arr[] = "ABCDEFG";
	print(arr);

	system("pause");
	return 0;
}