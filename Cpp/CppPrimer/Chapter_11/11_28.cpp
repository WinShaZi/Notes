#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
	map<string, vector<int>> msvi{
		{ "A", { 0, 1, 2, 3, 4 } },
		{ "B", { 5, 6, 7, 8, 9 } },
		{ "C", { 0, 0, 0, 0, 0 } }
	};

	auto iter = msvi.find("A");

	cout << iter->first << endl;
	
	system("pause");
	return 0;
} 