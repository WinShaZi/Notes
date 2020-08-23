#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

string &add(string &name, const string &front, const string &back)
{
	name.insert(name.begin(), front.begin(), front.end());
    name.reserve(name.size() + back.size());
    name.insert(name.end(), back.begin(), back.end());

	return name;
}

int main()
{
	string name;
    string front("Mr.");
    string back(" III");

    while (cin >> name)
        cout << add(name, front, back) << endl;

	system("pause");
	return 0;
}