#include <iostream>

using namespace std;

double light_au(double n);

int main()
{
	double len;

	cout << "Enter the number of light years : ";
	cin >> len;
	cout << len << " light years = " << light_au(len);
	cout << " astronomical units." << endl;

	system("pause");
	return 0;
}

double light_au(double n)
{
	return n * 63240;
}