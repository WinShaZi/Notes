
//move.h
//*******************************************************************************************

#ifndef MOVE_H_
#define MOVE_H_

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showmove() const;
	Move add(const Move& m) const;
	void reset(double a = 0, double b = 0);
};

#endif

//*******************************************************************************************

//move.cpp
//*******************************************************************************************

#include <iostream>
#include "move.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	std::cout << "x = " << x << ", and y = " << y << std::endl;
}

Move Move::add(const Move& m) const
{
	Move n;

	n.x = m.x + this->x;
	n.y = m.y + this->y;

	return n;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "move.h"

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;

	Move m0(1, 10);
	Move m1(2, 20);

	cout << "Now the first move is : " << endl;
	m0.showmove();
	cout << "Now the second move is : " << endl;
	m1.showmove();
	cout << "Please input your move : " << endl;

	double a, b;

	cout << "x : ";
	cin >> a;
	cout << "y : ";
	cin >> b;

	Move m2(a, b);

	cout << "So your move is : " << endl;
	m2.showmove();

	cout << "Now first move adds into your move : " << endl;
	m2 = m2.add(m0);
	m2.showmove();
	cout << "Now second move adds into your move : " << endl;
	m2 = m2.add(m1);
	m2.showmove();

	cout << "Now reset your move : " << endl;
	cout << "x : ";
	cin >> a;
	cout << "y : ";
	cin >> b;
	m2.reset(a, b);
	cout << "So your move is : " << endl;
	m2.showmove();

	cout << "Bye!" << endl;
	
	system("pause");
	return 0;
}

//*******************************************************************************************