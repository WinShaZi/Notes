
//mytime.h
//*******************************************************************************************

#ifndef MYTIME_H_
#define MYTIME_H_

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void ADDMin(int m);
	void ADDHr(int h);
	void Reset(int h = 0, int m = 0);
	friend Time operator+(const Time& s, const Time& t);
	friend Time operator-(const Time& s, const Time& t);
	friend Time operator*(const Time& t, double n);
	friend Time operator*(double m, const Time& t) { return t * m; }
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

#endif

//*******************************************************************************************

//mytime.cpp
//*******************************************************************************************

#include <iostream>
#include "mytime.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::ADDMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::ADDHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(const Time& s, const Time& t)
{
	Time sum;

	sum.minutes = s.minutes + t.minutes;
	sum.hours = s.hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;

	return sum;
}

Time operator-(const Time& s, const Time& t)
{
	Time diff;
	int tot1, tot2;

	tot1 = t.minutes + 60 * t.hours;
	tot2 = s.minutes + 60 * s.hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;

	return diff;
}

Time operator*(const Time& s, double mult)
{
	Time result;

	long totalminutes = s.hours * mult * 60 + s.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;

	return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";

	return os;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "mytime.h"

int main()
{
	using std::cout;
	using std::endl;

	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca : " << endl;
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + tosca : " << temp << endl;
	temp = aida * 1.17;
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca : " << 10.0 * tosca << endl;

	system("pause");
	return 0;
}

//*******************************************************************************************