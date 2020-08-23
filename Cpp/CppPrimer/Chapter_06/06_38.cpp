#include <iostream>
#include <string>

using namespace std;

string st[10];
decltype(st) &arrPtr(string (&st)[10])
{
	for (auto &n : st)
		n = "AAA";

	return st;
}

int main()
{
	string *ss = arrPtr(st);

	for (int i = 0; i < 10; i++)
		cout << *ss++ << endl;
	
	system("pause");
	return 0;
}