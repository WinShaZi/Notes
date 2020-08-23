
//golf.h
//*******************************************************************************************

#ifndef GOLF_H_
#define GOLF_H_

const int LEN = 40;

class Golf 
{
private:
	char _fullname[LEN];
	int _handicap;
public:
	Golf(const char* name, int hc = 0);
	int setgolf();
	void sethandicap(int hc);
	void showgolf()const;
};

#endif

//*******************************************************************************************

//golf.cpp
//*******************************************************************************************

#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf(const char* name, int hc)
{
	strcpy(_fullname, name);
	_handicap = hc;
}

int Golf::setgolf()
{
	using std::cout;
	using std::endl;
	using std::cin;

	static int i = 0; 

	cout << "#" << ++i << ":\n";
	cout << "Please enter the name : ";
	cin.getline(_fullname, 40);

	cout << "Please enter the grade :";
	cin >> _handicap;
	cin.get();

	Golf g(_fullname, _handicap);
	*this = g;

	return _fullname == "" ? 0 : 1;
}

void  Golf::sethandicap(int hc)
{
	_handicap = hc;
}

void Golf::showgolf()const
{
	using std::cout;
	using std::endl;
	cout << "The name of golf is : " << _fullname << endl;
	cout << "The grade of golf is : " << _handicap << endl;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "golf.h"

int main()
{
	using std::cout;
	using std::endl;

	Golf g("huangfu shuyun", 20);

	g.showgolf();
	cout << endl;
	g.setgolf();
	cout << endl;
	g.showgolf();
	cout << endl;
	g.sethandicap(100);
	g.showgolf();

	return 0;
}

//*******************************************************************************************