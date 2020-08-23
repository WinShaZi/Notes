#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main()
{
	vector<string> vs{ "vector", "deque", "deque", "list", "forward_list", "array", "array", "string" };
	list<string> ls(10);

	for (auto n : vs)
		cout << n << ' ';
	cout << endl;

	unique_copy(vs.begin(), vs.end(), ls.begin());

	for (auto n : ls)
		cout << n << ' ';
	cout << endl;

	system("pause");
	return 0;
}