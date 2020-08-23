
//stonewt.h
//*******************************************************************************************

#ifndef STONEWT_H_
#define STONEWT_H_

enum Mode { stoneps, intps, floatps };

class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
	int mode;
public:
	void setmode(Mode m);
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();

	friend Stonewt operator+(const Stonewt& a, const Stonewt& b);
	friend Stonewt operator-(const Stonewt& a, const Stonewt& b);
	friend Stonewt operator*(const Stonewt& a, double b);
	friend Stonewt operator*(double a, const Stonewt& b);

	friend bool operator>(const Stonewt& a, const Stonewt& b);
	friend bool operator<(const Stonewt& a, const Stonewt& b);
	friend bool operator>=(const Stonewt& a, const Stonewt& b);
	friend bool operator<=(const Stonewt& a, const Stonewt& b);
	friend bool operator==(const Stonewt& a, const Stonewt& b);
	friend bool operator!=(const Stonewt& a, const Stonewt& b);

	friend std::ostream& operator << (std::ostream& os, const Stonewt& s);
};

#endif

//*******************************************************************************************

//stonewt.cpp
//*******************************************************************************************

#include <iostream>
#include "stonewt.h"

using std::cout;
using std::endl;

void Stonewt::setmode(Mode m)
{
	mode = m;
}

Stonewt::Stonewt(double lbs)
{
	mode = 2;
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	mode = 0;
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
	mode = 2;
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{
}

Stonewt operator+(const Stonewt& a, const Stonewt& b)
{
	Stonewt t;
	if (a.mode == 0)
	{
		t.pds_left = a.pds_left + b.pds_left;
		t.stone = a.stone + b.stone + int(t.pds_left) / Stonewt::Lbs_per_stn;
		t.pds_left = int(t.pds_left) % Stonewt::Lbs_per_stn + t.pds_left - int(t.pds_left);
		t.mode = 0;
	}
	else if (a.mode == 1)
	{
		t.pounds = a.pounds + b.pounds;
		t.pounds = int(t.pounds + 0.5);
		t.mode = 1;
	}
	else
	{
		t.pounds = a.pounds + b.pounds;
		t.mode = 2;
	}

	return t;
}

Stonewt operator-(const Stonewt& a, const Stonewt& b)
{
	Stonewt t;
	if (a.mode == 0)
	{
		double t1, t2;
		t1 = a.stone * Stonewt::Lbs_per_stn + a.pds_left;
		t2 = b.stone * Stonewt::Lbs_per_stn + b.pds_left;
		t.stone = int((t1 - t2) / Stonewt::Lbs_per_stn);
		t.pds_left = (int(t1 - t2) % Stonewt::Lbs_per_stn) + t1 - t2 - int(t1 - t2);
		t.mode = 0;
	}
	else if (a.mode == 2)
	{
		t.pounds = a.pounds - b.pounds;
		t.mode = 2;
	}
	else
	{
		t.pounds = a.pounds - b.pounds;
		t.pounds = int(t.pounds + 0.5);
		t.mode = 1;
	}
	return t;
}

Stonewt operator*(const Stonewt& a, double b)
{
	Stonewt t;
	if (a.mode == 0)
	{
		t.pounds = a.pounds * b;
		t.stone = a.stone * b + int(t.pounds) / Stonewt::Lbs_per_stn;
		t.pds_left = int(t.pounds) % Stonewt::Lbs_per_stn + t.pounds - int(t.pounds);
		t.mode = 0;
	}
	else if (a.mode == 2)
	{
		t.pounds = a.pounds * b;
		t.mode = 2;
	}
	else
	{
		t.pounds = a.pounds * b;
		t.pounds = int(t.pounds + 0.5);
		t.mode = 1;
	}
	return t;
}

Stonewt operator*(double a, const Stonewt& b)
{
	Stonewt t;
	if (b.mode == 0)
	{
		t.pounds = b.pounds * a;
		t.stone = b.stone * a + int(t.pounds) / Stonewt::Lbs_per_stn;
		t.pds_left = int(t.pounds) % Stonewt::Lbs_per_stn + t.pounds - int(t.pounds);
		t.mode = 0;

	}
	else if (b.mode == 2)
	{
		t.pounds = b.pounds * a;
		t.mode = 2;
	}
	else
	{
		t.pounds = b.pounds * a;
		t.pounds = int(t.pounds + 0.5);
		t.mode = 1;
	}
	return t;
}

bool operator>(const Stonewt& a, const Stonewt& b)
{
	double t1, t2;

	if (a.mode == 0)
	{
		t1 = a.stone * Stonewt::Lbs_per_stn + a.pds_left;
	}
	else
	{
		t1 = a.pounds;
	}

	if (b.mode == 0)
	{
		t2 = b.stone * Stonewt::Lbs_per_stn + b.pds_left;
	}
	else
	{
		t2 = b.pounds;
	}
	return t1 > t2;
}

bool operator<(const Stonewt& a, const Stonewt& b)
{
	double t1, t2;
	if (a.mode == 0)
	{
		t1 = a.stone * Stonewt::Lbs_per_stn + a.pds_left;
	}
	else
	{
		t1 = a.pounds;
	}

	if (b.mode == 0)
	{
		t2 = b.stone * Stonewt::Lbs_per_stn + b.pds_left;
	}
	else
	{
		t2 = b.pounds;
	}
	return t1 < t2;
}

bool operator>=(const Stonewt& a, const Stonewt& b)
{
	double t1, t2;
	if (a.mode == 0)
	{
		t1 = a.stone * Stonewt::Lbs_per_stn + a.pds_left;
	}
	else
	{
		t1 = a.pounds;
	}

	if (b.mode == 0)
	{
		t2 = b.stone * Stonewt::Lbs_per_stn + b.pds_left;
	}
	else
	{
		t2 = b.pounds;
	}
	return t1 >= t2;
}


bool operator<=(const Stonewt& a, const Stonewt& b) {
	double t1, t2;
	if (a.mode == 0)
	{
		t1 = a.stone * Stonewt::Lbs_per_stn + a.pds_left;
	}
	else
	{
		t1 = a.pounds;
	}

	if (b.mode == 0)
	{
		t2 = b.stone * Stonewt::Lbs_per_stn + b.pds_left;
	}
	else
	{
		t2 = b.pounds;
	}
	return t1 <= t2;
}


bool operator==(const Stonewt& a, const Stonewt& b) {
	double t1, t2;
	if (a.mode == 0)
	{
		t1 = a.stone * Stonewt::Lbs_per_stn + a.pds_left;
	}
	else
	{
		t1 = a.pounds;
	}

	if (b.mode == 0)
	{
		t2 = b.stone * Stonewt::Lbs_per_stn + b.pds_left;
	}
	else
	{
		t2 = b.pounds;
	}
	return t1 == t2;
}


bool operator!=(const Stonewt& a, const Stonewt& b)
{
	{
		double t1, t2;
		if (a.mode == 0)
		{
			t1 = a.stone * Stonewt::Lbs_per_stn + a.pds_left;
		}
		else
		{
			t1 = a.pounds;
		}

		if (b.mode == 0)
		{
			t2 = b.stone * Stonewt::Lbs_per_stn + b.pds_left;
		}
		else
		{
			t2 = b.pounds;
		}
		return t1 != t2;
	}
}


std::ostream& operator << (std::ostream& os, const Stonewt& s)
{
	if (s.mode == 0)
	{
		os << s.stone << " stone, " << s.pds_left << " pounds" << endl;
	}
	else if (s.mode == 2)
	{
		os << s.pounds << " pounds" << endl;
	}
	else if (s.mode == 1)
	{

		os << int(s.pounds + 0.5) << " pounds" << endl;
	}
	else
	{
		os << "Stonewt object mode is invalid";
	}

	return os;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "stonewt.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	Stonewt incognito[6] = { 123.4,456.7,678.9 };
	for (int i = 3; i < 6; i++)
	{
		double n;
		cout << "Please enter the number #" << i + 1 << " : ";
		cin >> n;
		incognito[i] = n;
	}

	Stonewt stand(11, 0);
	Stonewt max;
	Stonewt min;
	int imax;
	int imin;
	max = min = incognito[0];
	imax = imin = 0;

	for (int i = 0; i < 6; i++)
	{
		if (min > incognito[i])
		{
			min = incognito[i];
			imin = i;
		}
		if (max < incognito[i])
		{
			max = incognito[i];
			imax = i;
		}
	}

	cout << "The max is : " << "incognito[" << imax << "] : " << max;
	cout << "The min is : " << "incognito[" << imin << "] : " << min;
	cout << "The weight more than 11 stone is : " << endl;
	for (int i = 0; i < 6; i++)
	{
		if (incognito[i] > stand)
			cout << "incognito[" << i << "] : " << incognito[i];
	}

	system("pause");
	return 0;
}

//*******************************************************************************************