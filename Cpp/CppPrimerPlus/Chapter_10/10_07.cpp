
//plorg.h
//*******************************************************************************************

#ifndef PLORG_H_
#define PLORG_H_

#include <cstring>

static const int LEN = 20;

class Plorg
{
private:
	char _name[LEN];
	int _ci;
public:
	Plorg() { strcpy(_name, "Plorga"); _ci = 0; }
	void setPlorg();
	void show();
};

#endif

//*******************************************************************************************

//plorg.cpp
//*******************************************************************************************

#include <iostream>
#include "plorg.h"

void Plorg::setPlorg()
{
	using std::cout;
	using std::endl;
	using std::cin;

	cout << "Input new name :";
	cin.getline(_name, LEN);
	cout << "Input new CI : ";
	cin >> _ci;
}

void Plorg::show()
{
	std::cout << "Name : " << _name << std::endl;
	std::cout << "CI : " << _ci << std::endl;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream> 
#include "plorg.h"

int main()
{
	Plorg p;

	p.show();
	p.setPlorg();
	p.show();


	system("pause");
	return 0;
}

//*******************************************************************************************