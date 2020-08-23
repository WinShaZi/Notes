
//person.h
//*******************************************************************************************

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

const int SIZE = 3;

using namespace std;

class Person
{
private:
	string first_name;
	string last_name;
public:
	Person() :first_name("none"), last_name("none") {}
	Person(const string& f_name, const string& l_name) :first_name(f_name), last_name(l_name) {}
	virtual void Show();
};

class Gunslinger :virtual public Person
{
private:
	int line_num;
	double shoot_time;
public:
	Gunslinger() :Person(), line_num(0), shoot_time(0) {}
	Gunslinger(const string& f_name, const string& l_name, int l_num, double s_time)
		:Person(f_name, l_name), line_num(l_num), shoot_time(s_time) {}
	double Draw();
	virtual void Show();
};

class PokerPlayer :virtual public Person
{
public:
	PokerPlayer() :Person() {}
	PokerPlayer(const string& f_name, const string& l_name) :Person(f_name, l_name) {}
	int Draw();
	virtual void Show();
};

class BadDuke :public Gunslinger, public PokerPlayer
{
public:
	BadDuke() :Person(), Gunslinger(), PokerPlayer() {}
	BadDuke(const string& f_name, const string& l_name, int l_num, double s_time) 
		:Person(f_name, l_name), Gunslinger(f_name, l_name, l_num, s_time), PokerPlayer(f_name, l_name) {}
	double Gdraw();
	int Cdraw();
	virtual void Show();
};

#endif

//*******************************************************************************************

//person.cpp
//*******************************************************************************************

#include "person.h"

void Person::Show()
{
	cout << "First name : " << first_name << endl;
	cout << "Last name : " << last_name << endl;
}

double Gunslinger::Draw()
{
	return shoot_time;
}

void Gunslinger::Show()
{
	cout << endl;
	Person::Show();
	cout << "Line number : " << line_num << endl;
	cout << "Shoot time : " << shoot_time << endl;
}

int PokerPlayer::Draw()
{
	return rand() % 52 + 1;
}

void PokerPlayer::Show()
{
	cout << endl;
	Person::Show();
}

double BadDuke::Gdraw()
{
	return Gunslinger::Draw();
}

int BadDuke::Cdraw()
{
	return PokerPlayer::Draw();
}

void BadDuke::Show()
{
	cout << endl;
	Person::Show();
	cout << "Next shoot time : " << Gdraw() << endl;
	cout << "Next poker : " << Cdraw() << endl;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include "person.h"

int main()
{
	Person* ps[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choose;

		cout << "Input a letter : " << endl;
		cout << "G. Gunslinger\tP. PokerPlayer\tB. BadDuke\tQ. Quit" << endl;
		cin >> choose;
		choose = toupper(choose);
		while (strchr("GPBQ", choose) == nullptr)
		{
			cout << "Input a letter (GPBQ): " << endl;
			cin >> choose;
			cin.get();
			choose = toupper(choose);
		}
		if (choose == 'Q')
			break;
		switch (choose)
		{
		case'G':ps[ct] = new Gunslinger("Gun", "Slinger", 3, 7.7); break;
		case'P':ps[ct] = new PokerPlayer("Poker", "Player"); break;
		case'B':ps[ct] = new BadDuke("Bad", "Duke", 3, 4.0); break;
		default:ps[ct] = nullptr; break;
		}
		while (cin.get() != '\n');
	}
	if (ct != 0)
	{
		cout << "Here is your message : " << endl;
		for (int i = 0; i < ct; i++)
			ps[i]->Show();
	}
	cout << "Bye" << endl;

	system("pause");
	return 0;
}

//*******************************************************************************************