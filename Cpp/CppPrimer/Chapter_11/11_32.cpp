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

	for (auto n : mss)
		cout << n.first << ' ' << n.second << endl;
	cout << endl;
	
	system("pause");
	return 0;
} 