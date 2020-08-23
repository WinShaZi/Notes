#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

int main()
{
	map<string, int> msi;
	msi["string"] = 1;
	map<string, int>::iterator iter = msi.begin();

	iter->second = strlen("string");
	cout << iter->first << ' ' << iter->second << endl;

	system("pause");
	return 0;
}