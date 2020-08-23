
//port.h
//*******************************************************************************************

#ifndef PORT_H_
#define PORT_H_

#include <iostream>

class Port
{
private:
	char* brand;
	char style[20];
	int bottles;
public:
	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& p);
	virtual ~Port() { delete[]brand; }
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int BottleCount()const { return bottles; }
	virtual void Show()const;
	friend std::ostream &operator<<(std::ostream& os, const Port& p);
};

class VintagePort :public Port
{
private:
	char* nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char* br, const char* st, int b, const char* nn, int y);
	VintagePort(const VintagePort& vp);
	~VintagePort() { delete[]nickname; }
	VintagePort& operator=(const VintagePort& vp);
	virtual void Show()const;
	friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};

#endif

//*******************************************************************************************

//port.cpp
//*******************************************************************************************

#include <cstring>
#include "port.h"

Port::Port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}

Port::Port(const Port& p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port& Port::operator=(const Port &p)
{
	if (this == &p)
		return *this;
	delete[]brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;

	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;

	return *this;
}

Port& Port::operator-=(int b)
{
	if (b > bottles)
		std::cout << "Not enough" << std::endl;
	else
		bottles -= b;

	return *this;
}

void Port::Show()const
{
	std::cout << "Brand : " << brand << std::endl;
	std::cout << "Kind : " << style << std::endl;
	std::cout << "Bottles : " << bottles << std::endl << std::endl;
}

std::ostream &operator<<(std::ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.BottleCount() << std::endl << std::endl;

	return os;
}

VintagePort::VintagePort() :Port()
{
	nickname = new char[1];
	nickname[0] = '\0';
	year = 0;
}

VintagePort::VintagePort(const char* br, const char* st, int b, const char* nn, int y) :Port(br, st, b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp) :Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete[]nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;

	return *this;
}

void VintagePort::Show()const
{
	Port::Show();
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Year : " << year << std::endl << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	os << (const Port&)vp;
	os << vp.nickname << ", " << vp.year << std::endl << std::endl;

	return os;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include "port.h"

int main()
{
	Port p1("Gallo", "tawny", 20), p2;
	VintagePort vp1("Romane Conti", "potpourri", 30, "Conti", 1997), vp2(vp1);

	p1.Show();
	p2.Show();
	vp1.Show();
	vp2.Show();

	p2 = p1;
	p2.Show();

	p2 += 3;
	p2 -= 2;
	vp2 += 5;
	vp2 -= 1;

	p2.Show();
	vp2.Show();

	std::cout << p1 << std::endl;
	std::cout << vp1 << std::endl;

	system("pause");
	return 0;
}

//*******************************************************************************************