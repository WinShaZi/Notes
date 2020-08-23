#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
	set<string> ss{ "aa", "bb", "cc", "dd", "ee" };
    string temp;

    while (cin >> temp && temp != "q")
    {
        cout << temp << ' ' 
            << (binary_search(ss.begin(), ss.end(), temp) ? "existing" : (ss.insert(temp), "new word")) << endl;
    }

    for (auto n : ss)
        cout << n << ' ';
    cout << endl;
	
	system("pause");
	return 0;
}

//查找速度快