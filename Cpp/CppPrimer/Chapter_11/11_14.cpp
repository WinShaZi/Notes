#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	map<string, vector<pair<string, string>>> family;
    string last_name, first_name, birthday; 
    vector<string> first;

    cout << "Input last_name name : " << endl;
    while (cin >> last_name && last_name != "q")
    {
        cout << "Input first name and birthday : " << endl;
        while (cin >> first_name >> birthday && first_name != "q" && birthday != "q")
            family[last_name].push_back(make_pair(first_name, birthday));
        cout << "Input last_name name : " << endl;
    }

    for (auto n : family)
    {
        cout << n.first << "\t\t";
        for (auto m : n.second)
            cout << n.first << ' ' << m.first << ' ' << m.second << '\t';
        cout << endl;
    }
    cout << endl;
	
	system("pause");
	return 0;
} 