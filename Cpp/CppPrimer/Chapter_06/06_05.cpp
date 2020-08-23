#include <iostream>

using namespace std;

int fact(int val)
{
	if (val < 0)
		val = -val;

	return val;
}

int main()
{
	int val;

	if (cin >> val)
		cout << fact(val) << endl;	

	system("pause");
	return 0;
}