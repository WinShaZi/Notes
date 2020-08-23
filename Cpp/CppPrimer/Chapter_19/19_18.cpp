#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> vs = {"a", "bb", "", "ccc", ""};

	function<bool (const string)> fcn = string::empty;

	auto it1 = find_if(vs.begin(), vs.end(), fcn);
	cout << "function: " << it1 - vs.begin() << endl;

	auto it2 = find_if(vs.begin(), vs.end(), mem_fn(&string::empty));
	cout << "mem_fn: " << it2 - vs.begin() << endl;

	auto it3 = find_if(vs.begin(), vs.end(), bind(&string::empty, placeholders::_1));
	cout << "bind: " << it3 - vs.begin() << endl;

	cout << "count_if: " << count_if(vs.begin(), vs.end(), fcn) << endl;

    system("pause");
	return 0;
}