
//winec.h
//*******************************************************************************************

#ifndef WINE_H_
#define WINE_H_

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

template <class T1,class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1& first() { return a; }
	T2& second() { return b; }
	T1 first()const { return a; }
	T2 second()const { return b; }
	Pair(const T1& aval, const T2& bval) :a(aval), b(bval) {}
	Pair() {}
};

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	string label;
	PairArray number;
	int year;
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	Wine() :label("none"), number(), year(0) {}
	void GetBottles();
	void Show();
	const string& Label();
	int sum();

};

#endif

//*******************************************************************************************

//winec.cpp
//*******************************************************************************************

#include "winec.h"

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
	label = l;
	year = y;
	ArrayInt a(yr, y);
	ArrayInt b(bot, y);
	number = Pair(a, b);
}

Wine::Wine(const char* l, int y)
{
	label = l;
	year = y;
	number = PairArray();
}

const std::string& Wine::Label()
{
	return label;
}

void Wine::GetBottles()
{
	ArrayInt yr(year);
	ArrayInt bot(year);
	std::cout << "Enter " << label << " data for " << year << " year(s) : " << endl;
	for (int i = 0; i < year; i++)
	{
		std::cout << "Enter year : ";
		std::cin >> yr[i];
		std::cout << "Enter bottles for that year : ";
		std::cin >> bot[i];
	}
	number = PairArray(yr, bot);
}

void Wine::Show()
{
	cout << "Wine : " << label << endl;
	cout << "\tyear\tbottles" << endl;
	for (int i = 0; i < year; i++)
		cout << '\t' << number.first()[i] << '\t' << number.second()[i] << endl;
}

int Wine::sum()
{
	int count = 0;

	for (int i = 0; i < year; i++)
		count += number.second()[i];

	return count;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include "winec.h"

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Enter name of wine : ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years : ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label()
		<< " : " << more.sum() << endl;
	cout << "Bye\n";

	return 0;
}

//*******************************************************************************************