
//exc_hmean.h
//*******************************************************************************************

#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

using namespace std;

class mean :public logic_error
{
private:
	double v1;
	double v2;
public:
	mean(double a = 0, double b = 0, const string & st = "error") :logic_error(st), v1(a), v2(b) {}
	virtual void report()const = 0;
};

class bad_hmean :public mean
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0, const string & st = "error") :mean(a, b, st), v1(a), v2(b) {}
	virtual void report()const;
};

class bad_gmean :public mean
{
private:
	double v1;
	double v2;
public:
	bad_gmean(double a = 0, double b = 0, const string & st = "error") :mean(a, b, st), v1(a), v2(b) {}
	virtual void report()const;
};

void bad_hmean::report()const
{
	cout << v1 << ", " << v2 << endl;
	cout << "ERROR : a = -b" << endl;
	cout << what() << endl;
}

void bad_gmean::report()const
{
	cout << v1 << ", " << v2 << endl;
	cout << "ERROR : a < 0 || b < 0" << endl;
	cout << what() << endl;
}

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
		catch (mean& em)
		{
			em.report();
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
		throw bad_hmean(a, b, "bad_hmean error : a = -b");
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b, "bad_gmean error : a < 0 || b < 0");
	return sqrt(a * b);
}

//*******************************************************************************************