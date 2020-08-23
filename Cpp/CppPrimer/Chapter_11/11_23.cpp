#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
	multimap<string, string> family;
    string last, temp;

    cout << "Input last name : " << endl;
    while (cin >> last && last != "quit")
    {
        cout << "Input first name : " << endl;
        if (!(cin >> temp) || temp == "quit")
            break;
        family.emplace(last, temp);
        cout << "Input last name : " << endl;
    }

    for (auto n : family)
        cout << n.first << ' ' << n.second << endl;
    cout << endl;
	
	system("pause");
	return 0;
} 