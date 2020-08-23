#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

void choose(const string &st)
{
	const string letter("bdfghijklpqty");
	string temp = "none";
	int  i = 1;

	if ((i = st.find_first_of(letter)) != 0)
		temp = st.substr(0, i);

	cout << temp << endl;
}

int main()
{
	string st;

	while (cin >> st)
		choose(st);

	system("pause");
	return 0;
}