#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <functional>

using namespace std;

int add(int n, int m)
{
	return n + m;
}

int minu(int n, int m)
{
	return n - m;
}

int mult(int n, int m)
{
	return n * m;
}

int divi(int n, int m)
{
	if (0 == m)
		return INT32_MAX;
	return n / m;
}

int main()
{
	map<string, function<int (int, int)>> calc{
		{ "+", add },
		{ "-", minu },
		{ "*", mult },
		{ "/", divi }
	};

	int i;
	int j;
	string st;

	while (cin >> i >> st >> j)
		cout << i << ' ' << st << ' ' << j << ' ' << '=' << ' ' << calc[st](i, j) << endl;

	system("pause");
	return 0;
}