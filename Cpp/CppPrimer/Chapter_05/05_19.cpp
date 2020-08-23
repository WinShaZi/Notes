#include <iostream>

using namespace std;

int main()
{
	string st1;
	string st2;

	cin >> st1 >> st2;
	do
	{
		cout << (st1.size() < st2.size() ? st1 : st2) << endl;
	} while (cin >> st1 >> st2);

	system("pause");
	return 0;
}