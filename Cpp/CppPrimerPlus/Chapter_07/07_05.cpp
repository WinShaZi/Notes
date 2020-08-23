#include <iostream>

using namespace std;

long double factorial(int n);

int main()
{
	int i;

	cout << "Input : ";
	while (cin >> i && i >= 0)
		cout << factorial(i) << endl << "Input : ";

	system("pause");
	return 0;
}

long double factorial(int n)
{
	if (n == 0)
		return 1;

	return n * factorial(n - 1);
}