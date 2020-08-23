#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool re(string& s);

int main()
{
	string s;

	cout << "Input : ";
	while (getline(cin, s) && s != "q")
	{
		if (re(s))
			cout << "Yes" << endl;
		else
			cout << "NO" << endl;
		cout << "Input : ";
	}
	cout << "Bye" << endl;

	system("pause");
	return 0;
}

bool re(string& s)
{
	string::iterator pd;

	for (pd = s.begin(); pd != s.end(); )
		if (!isalpha(*pd) || isspace(*pd))
			s.erase(pd);
		else
		{
			*pd = tolower(*pd);
			pd++;
		}

	string temp = s;

	reverse(temp.begin(), temp.end());

	return temp == s;
}