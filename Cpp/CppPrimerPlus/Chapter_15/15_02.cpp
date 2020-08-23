
//exc_hmean.h
//*******************************************************************************************

#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

using namespace std;

class bad_hmean :public logic_error
{
public:
	bad_hmean(const string& st = "error") :logic_error(st) {}
};

class bad_gmean :public logic_error
{
public:
	bad_gmean(const string& st = "error") :logic_error(st) {}
};

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include "exc_hmean.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	double x, y;

	cout << "Enter two numbers : ";
	while (cin >> x >> y)
	{
		try {
			cout << "Harmonic mean of " << x << " and " << y << " is " << hmean(x, y) << endl;
			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers : ";
		}
		catch (logic_error& le)
		{
			cout << le.what() << endl;
			cout << "Try again." << endl;
			cout << "Input : ";
			continue;
		}
	}

	cout << "Bye!" << endl;

	system("pause");
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean("bad_hmean error : a = -b");
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean("bad_gmean error : a < 0 || b < 0");
	return sqrt(a * b);
}

//*******************************************************************************************