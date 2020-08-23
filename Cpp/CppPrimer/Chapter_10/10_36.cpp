#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

int main()
{
	list<int> vi { 1, 0, 1, 1, 0, 0, 1 };

	cout << *find(vi.crbegin(), vi.crend(), 0) << endl;

	system("pause");
	return 0;
}