#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	string str[] = { "A", "B", "C", "D", "E", "D", "C", "B", "A" };
	list<string> ls(str, str + 8);
	string st;

	while (cin >> st)
		cout << count(ls.begin(), ls.end(), st) << endl;

	system("pause");
	return 0;
}