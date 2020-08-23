#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
	multimap<string, string> mss{
		{ "Stanley", "C++ Primer" },
		{ "Stephen", "C Primer Plus"},
		{ "Nicolai", "C++ STL"},
		{ "Stephen", "C++ Primer Plus" }
	};

	string st;

	while (cin >> st)
	{
		for (auto beg = mss.lower_bound(st), end = mss.upper_bound(st); beg != end; ++beg)
			cout << beg->second << endl;
		for (multimap<string, string>::iterator iter; (iter = mss.find(st)) != mss.end();)
			 mss.erase(iter);
	}

	for (auto n : mss)
		cout << n.first << ' ' << n.second << endl;
	cout << endl;
	
	system("pause");
	return 0;
} 