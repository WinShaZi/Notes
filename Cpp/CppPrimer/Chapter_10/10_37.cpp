#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> vi { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> li(5);

	copy(vi.crend() - 7, vi.crend() - 2, li.begin());

	for (auto n : li)
		cout << n << ' ';
	cout << endl;

	system("pause");
	return 0;
}