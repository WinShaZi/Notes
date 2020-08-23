#include <iostream>

using namespace std;

double aver(double n, double m);

int main()
{
	double x, y;

	while (cin >> x >> y && x > 0 && y > 0)
		cout << aver(x, y) << endl;

	system("pause");
	return 0;
}

double aver(double n, double m)
{
	return 2.0 * n * m / (n + m);
}