#include <iostream>

using namespace std;

int main()
{
	float i, j;

	while (cin >> i >> j && j > 0.000001 && j < -0.000001)
		cout << i / j << endl;

	system("pause");
	return 0;
}