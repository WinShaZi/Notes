#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool re(const string& s)
{
	string temp = s;

	reverse(temp.begin(), temp.end());

	return temp == s;
}

int main()
{
	string s;

	cout << "Input : ";
	while (cin >> s)
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