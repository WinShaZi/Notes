#include <iostream>

using namespace std;

double cel_fah(double n);

int main()
{
	double temp;

	cout << "Please enter a Celsius value : ";
	cin >> temp;
	cout << temp << " degrees Celsius is " << cel_fah(temp);
	cout << " degrees Fahrenheit." << endl;

	system("pause");
	return 0;
}

double cel_fah(double n)
{
	return 1.8 * n + 32;
}