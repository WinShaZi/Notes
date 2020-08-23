
//abc.h
//*******************************************************************************************

#ifndef ABC_H_
#define ABC_H_

#include <iostream>

class ABC
{
private:
	char* _label;
	int _rating;
public:
	ABC(const char* label = "null", int rating = 0);
	virtual ~ABC();
	virtual void View() = 0;
};

class baseDMA :public ABC
{
public:
	baseDMA(const char* label = "null", int rating = 0);
	virtual void View();
};

class lacksDMA :public ABC
{
private:
	char _color[40];
public:
	lacksDMA(const char* c = "blank", const char* label = "null", int rating = 0);
	virtual void View();
};

class hasDMA :public ABC
{
private:
	char* _style;
public:
	hasDMA(const char* s = "none", const char* label = "null", int rating = 0);
	~hasDMA();
	virtual void View();
};

#endif

//*******************************************************************************************

//abc.cpp
//*******************************************************************************************

#include <cstring>
#include "abc.h"

using std::cout;
using std::endl;

ABC::ABC(const char* label, int rating)
{
	_label = new char[std::strlen(label) + 1];
	strcpy(_label, label);
	_rating = rating;
}

ABC::~ABC()
{
	delete[] _label;
}

void ABC::View()
{
	cout << "label:" << _label << endl;
	cout << "Rating:" << _rating << endl;
}

baseDMA::baseDMA(const char* label, int rating) :ABC(label, rating)
{

}

void baseDMA::View()
{
	ABC::View();
}

lacksDMA::lacksDMA(const char* color, const char* label, int rating) :ABC(label, rating)
{
	strcpy_s(_color, color);
	_color[39] = '\0';
}

void lacksDMA::View()
{
	ABC::View();
	cout << "Color:" << _color << endl;
}

hasDMA::hasDMA(const char* style, const char* label, int rating) : ABC(label, rating)
{
	_style = new char[strlen(style) + 1];
	strcpy(_style, style);
}

hasDMA::~hasDMA()
{
	delete[] _style;
}

void hasDMA::View()
{
	ABC::View();
	cout << "Style:" << _style << endl;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include "abc.h"

const int BASE = 3;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	ABC* p_base[BASE];
	char t_label[40];
	char t_color[40];
	char t_style[40];
	int t_rating;
	int kind = 0;

	for (int i = 0; i < BASE; i++)
	{
		cout << "Enter base's label : ";
		cin.get(t_label, 40);
		cout << "Enter base's rating : ";
		cin >> t_rating;
		cout << "Enter 1 for base, 2 for lacksbase or 3 for hasbase : ";
		while (cin >> kind && (kind < 1 || kind > 3))
			cout << "Enter either 1 , 2 or 3 : ";
		if (kind == 0)
			exit(EXIT_FAILURE);
		while (cin.get() != '\n');
		if (kind == 1)
			p_base[i] = new baseDMA(t_label, t_rating);
		else if (kind == 2)
		{
			cout << "Enter the color : ";
			cin.get(t_color, 40);
			p_base[i] = new lacksDMA(t_color, t_label, t_rating);
		}
		else if (kind == 3)
		{
			cout << "Enter the style : ";
			cin.getline(t_style, 40);
			p_base[i] = new hasDMA(t_style, t_label, t_rating);
		}
		while (cin.get() != '\n');
	}
	cout << endl;
	for (int i = 0; i < BASE; i++)
	{
		p_base[i]->View();
		cout << endl;
	}

	for (int i = 0; i < BASE; i++)
	{
		delete p_base[i];
	}
	cout << "Done." << endl;

	system("pause");
	return 0;
}

//*******************************************************************************************