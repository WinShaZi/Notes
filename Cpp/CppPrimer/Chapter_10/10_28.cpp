#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

using namespace std;

template<class T>
void show(T &t)
{
	for (auto n : t)
		cout << n << ' ';
	cout << endl;
}

int main()
{
	vector<int> vi{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> li;
	deque<int> di;
	forward_list<int> fli;


	copy(vi.begin(), vi.end(), back_inserter(li));
	copy(vi.begin(), vi.end(), inserter(di, di.begin()));
	copy(vi.begin(), vi.end(), front_inserter(fli));

	show(vi);
	show(li);
	show(di);
	show(fli);

	system("pause");
	return 0;
}