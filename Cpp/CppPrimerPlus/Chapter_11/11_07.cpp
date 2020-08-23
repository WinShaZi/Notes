
//complex.h
//*******************************************************************************************

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

class Complex
{
private:
	double _x;
	double _y;
public:
	Complex();
	Complex(const double x, const double y);
	Complex operator+(const Complex& com)const;
	Complex operator-(const Complex& com)const;
	Complex operator*(const Complex& com)const;
	
	friend Complex operator*(const double n, const Complex& com);
	friend Complex operator~(const Complex& com);
	friend std::istream& operator>>(std::istream& ins, Complex& c);
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif

//*******************************************************************************************

//complex.cpp
//*******************************************************************************************

#include <iostream>
#include "complex.h"

using std::cout;
using std::endl;

Complex::Complex()
{
	_x = 0.0;
	_y = 0.0;
}

Complex::Complex(const double x, const double y)
{
	_x = x;
	_y = y;
}

Complex Complex::operator+(const Complex& com)const
{
	Complex temp;

	temp._x = _x + com._x;
	temp._y = _y + com._y;

	return temp;
}

Complex Complex::operator-(const Complex& com)const
{
	Complex temp;

	temp._x = _x - com._x;
	temp._y = _y - com._y;

	return temp;
}

Complex Complex::operator*(const Complex& com)const
{
	Complex temp;

	temp._x = _x * com._x - _y * com._y;
	temp._y = _x * com._y + _y * com._x;

	return temp;
}

Complex operator*(const double n,const Complex& com)
{
	Complex temp;

	temp._x = n * com._x;
	temp._y = n * com._y;

	return temp;
}

Complex operator~(const Complex& com)
{
	Complex temp;

	temp._x = com._x;
	temp._y = -com._y;

	return temp;
}

std::istream& operator>>(std::istream& is, Complex& com)
{
	cout << "real : ";
	if (!(is >> com._x))
		return is;

	cout << "imaginary : ";
	is >> com._y;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Complex& com)
{
	os << "( " << com._x << ", " << com._y << "i )";

	return os;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
	Complex a(3.0, 4.0);
	Complex c;

	cout << "Enter a complex number (q to quit): " << endl;
	while (cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';
		cout << "a is " << a << '\n';
		cout << "a + c is " << a + c << endl;
		cout << "a - c is " << a - c << endl;
		cout << "a * c is " << a * c << endl;
		cout << "2 * c is " << 2 * c << endl;
		cout << "Enter a complex number (q to quit): " << endl;
	}
	cout << "Done!" << endl;

	system("pause");
	return 0;
}

//*******************************************************************************************