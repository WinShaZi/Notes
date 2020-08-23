#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using PSI = pair<string, int>;

inline void show(const vector<PSI> &vp)
{
	for (auto n : vp)
		cout << n.first << ' ' << n.second << endl;
	cout << endl;
}

int main()
{
	PSI pa;
	vector<PSI> vp1, vp2, vp3;
	string st;
	int i;

	while (cin >> st >> i)
	{
		vp1.push_back(PSI(st, i));
		vp2.push_back({ st, i });
		vp3.push_back(make_pair(st, i));
	}

	vector<vector<PSI>> vvp{ vp1, vp2, vp3 };

	for (auto n : vvp)
		show(n);


	system("pause");
	return 0;
}