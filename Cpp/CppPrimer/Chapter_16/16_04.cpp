#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template<typename Iter, typename T>
Iter find(Iter beg, Iter end, const T &t)
{
	for (auto it = beg; it != end; it++)
		if (*it == t)
			return it;
	return end;
}

int main()
{
	vector<string> vs{ "you", "can", "you", "up" };
	list<string> ls{ "no", "can", "no", "bb" };

	cout << *find(vs.begin(), vs.end(), "can") << endl;
	cout << *find(ls.begin(), ls.end(), "can") << endl;

	system("pause");
	return 0;
}