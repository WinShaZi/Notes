#include <iostream>

using namespace std;

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main()
{
	double a, b;
	double (*pf[4])(double a, double b);

	pf[0] = add;
	pf[1] = subtract;
	pf[2] = multiply;
	pf[3] = divide;

	cout << "Enter two numbers : ";
	while (cin >> a >> b)
	{
		for (int i = 0; i < 4; i++)
			cout << "The answer is : " << (*pf[i])(a, b) << endl;
		cout << "Enter two numbers : ";
	}
	cout << "Done!" << endl;
	return 0;
}

double add(double a, double b)
{
	return a + b;
}

double subtract(double a, double b)
{
	return a - b;
}

double multiply(double a, double b)
{
	return a * b;
}

double divide(double a, double b)
{
	return a / b;
}