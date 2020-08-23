#include <iostream>
#include <vector>

using namespace std;

int add(int i, int j)
{
	return i + j;
}

int sub(int i, int j)
{
	return i - j;
}

int muli(int i, int j)
{
	return i * j;
}

int divi(int i, int j)
{
	return j == 0 ? 0 : i / j;
}

int main()
{
	using pfunc = int(int, int);
	vector<pfunc *> pf{ add, sub , muli, divi };

	for (auto n : pf)
		cout << n(1, 1) << endl;

	system("pause");
	return 0;
}