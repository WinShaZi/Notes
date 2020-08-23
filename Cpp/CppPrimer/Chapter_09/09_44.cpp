#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

string &change(string &s, const string &oldVal, const string &newVal)
{
	for (auto i = s.size() - s.size(); i < s.size();)
	{
		if (s.substr(i, oldVal.size()) == oldVal)
		{
			s = s.replace(i, oldVal.size(), newVal);
			i += newVal.size();
		}
		else
			i++;
	}

	return s;
}

int main()
{
	string s("tho the tho");
	string oldVal("tho");
	string newVal("though");

	cout << change(s, oldVal, newVal) << endl;

	system("pause");
	return 0;
}