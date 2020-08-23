#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double PI = 3.14;

class Geomentry
{
private:
	double _area;
public:
	Geomentry(double area = 0) : _area(area) { }
	void show() const;
};

class Square : public Geomentry
{
private:
	double _SquareLength;
public:
	Square(double SquareLength = 0) 
		: Geomentry(SquareArea(SquareLength)), _SquareLength(SquareLength) { }
	double SquareArea(const double SquareLength);
};

class Circle : public Geomentry
{
private:
	double _CircleRadial;
public:
	Circle(double CircleRadial = 0) 
		: Geomentry(CircleArea(CircleRadial)), _CircleRadial(CircleRadial) { }
	double CircleArea(const double CircleRadial);
};

void Geomentry::show() const
{
	cout << "Area : " << _area << endl;
	cout << endl; 
}

double Square::SquareArea(const double SquareLength)
{
	_SquareLength = SquareLength;

	return pow(SquareLength, 2);
}

double Circle::CircleArea(const double CircleRadial)
{
	_CircleRadial = CircleRadial;

	return PI * pow(CircleRadial, 2);
}

int main()
{
	Square S(10);
	Circle C(10);

	S.show();
	C.show();

	system("pause");
	return 0;
}