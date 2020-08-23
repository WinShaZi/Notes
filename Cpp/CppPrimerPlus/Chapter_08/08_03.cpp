#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void upper(string& st);

int main()
{
	string str;

	cout << "Enter a string (q to quit): ";
	while (getline(cin, str) && str != "q")
		upper(str);

	system("pause");
	return 0;
}

void upper(string& st)
{
	for (int i = 0; i < st.size(); i++)
		st[i] = toupper(st[i]);
	cout << st << endl;
	cout << "Enter a string (q to quit): ";
}