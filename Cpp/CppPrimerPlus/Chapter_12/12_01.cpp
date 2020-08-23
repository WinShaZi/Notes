
//cow.h
//*******************************************************************************************

#ifndef COW_H_
#define COW_H_

class Cow
{
private:
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow& c);
	~Cow();
	Cow& operator=(const Cow& c);
	void ShowCow()const;
};

#endif

//*******************************************************************************************

//cow.cpp
//*******************************************************************************************

#include <iostream>
#include <cstring>
#include "cow.h"

using namespace std;

Cow::Cow()
{
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	hobby = new char[strlen(ho) + 1];
	strcpy(name, nm);
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	hobby = new char[strlen(c.hobby) + 1];
	strncpy(name, c.name, 19);
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (&c == this)
		return *this;

	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strncpy(name, c.name, 19);
	strcpy(hobby, c.hobby);
	weight = c.weight;

	return *this;
}

void Cow::ShowCow()const
{
	cout << "The cow name is : " << name << endl;
	cout << "The cow hobby is : " << hobby << endl;
	cout << "The cow weight is : " << weight << endl;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include "cow.h"

int main()
{
	Cow c1;

	c1.ShowCow();
	
	Cow c2("AAA", "BBB", 100);

	c2.ShowCow();

	Cow c3(c2);

	c3.ShowCow();

	system("pause");
	return 0;
}

//*******************************************************************************************