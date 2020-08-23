#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
	map<string, vector<string>> family;
    string last, temp;

    cout << "Input last name : " << endl;
    while (cin >> last && last != "quit")
    {
        cout << "Input first name : " << endl;
        while (cin >> temp && temp != "quit")
            family[last].push_back(temp);
        cout << "Input last name : " << endl;
    }

    for (auto n : family)
    {
        cout << n.first << "\t\t";
        for (auto m : n.second)
            cout << n.first << ' ' << m << '\t';
        cout << endl;
    }
    cout << endl;
	
	system("pause");
	return 0;
} 