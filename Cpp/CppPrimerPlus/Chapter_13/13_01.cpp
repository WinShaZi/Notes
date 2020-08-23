
//cd.h
//*******************************************************************************************

#ifndef CD_H_
#define CD_H_

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();
	virtual void Report()const;
	Cd& operator=(const Cd& d);
};

class Classic :public Cd
{
private:
	char main_music[20];
public:
	Classic(const char* s1, const char* s2, const char* s3, int n, double x);
	Classic(const Classic& c, const char* s3);
	Classic();
	virtual void Report()const;
	Classic& operator=(const Classic& c);
};

#endif

//*******************************************************************************************

//cd.cpp
//*******************************************************************************************

#include <iostream>
#include <cstring>
#include "cd.h"

using std::cout;
using std::endl;

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	strcpy(performers, "None");
	strcpy(label, "None");
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{

}

void Cd::Report()const
{
	cout << "Performers : " << performers << endl;
	cout << "Label : " << label << endl;
	cout << "Number of selections : " << selections << endl;
	cout << "Playing time in minutes : " << playtime << endl;
	cout << endl;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x) :Cd(s1, s2, n, x)
{
	strcpy(main_music, s3);
}

Classic::Classic(const Classic& c, const char* s3) : Cd(c)
{
	strcpy(main_music, s3);
}

Classic::Classic()
{
	strcpy(main_music, "None");
}

void Classic::Report()const
{
	Cd::Report();

	cout << "Main music : " << main_music << endl;
	cout << endl;
}

Classic& Classic::operator=(const Classic& c)
{
	if (this == &c)
		return *this;
	Cd::operator=(c);
	strcpy(main_music, c.main_music);

	return *this;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "cd.h"

using std::cout;
using std::endl;

void Bravo(const Cd& disk);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;

	cout << "Using object directly : " << endl;
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to objects : " << endl;
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function with a Cd reference argument : " << endl;
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment : ";
	Classic copy;
	copy = c2;
	copy.Report();

	system("pause");
	return 0;
}

void Bravo(const Cd& disk)
{
	disk.Report();
}

//*******************************************************************************************