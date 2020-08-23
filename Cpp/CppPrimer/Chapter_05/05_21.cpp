#include <iostream>

using namespace std;

int main()
{
	string st;
	string st_prev;
	bool mode = true;

	while (cin >> st)
	{
		if (isupper(st[0]) && st == st_prev)
		{
			cout << "Same" << endl;
			mode = false;
			break;
		}
		st_prev = st;
	}
	if (mode)
		cout << "No same" << endl;

	system("pause");
	return 0;
}