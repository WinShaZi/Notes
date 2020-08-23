#include <iostream>
#include <string>

using namespace std;

string (&add(string (&st)[10]))[10]
{
	for (auto &n : st)
		n = "AAA";

	return st;
}

int main()
{
	string st[10];

	string *ss = st;
	ss = add(st);

	for (int i = 0; i < 10; i++)
		cout << *ss++ << endl;

	system("pause");
	return 0;
}