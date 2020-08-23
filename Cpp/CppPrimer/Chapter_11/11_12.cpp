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

int main()
{
	PSI pa;
    vector<PSI> vp;
    string st;
    int i;

    while (cin >> st >> i)
    {
        pa.first = st;
        pa.second = i;
        vp.push_back(pa);
    }
    
    for (auto n : vp)
        cout << n.first << ' ' << n.second << endl;

	system("pause");
	return 0;
} 