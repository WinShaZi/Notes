
//person.h
//*******************************************************************************************

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person
{
private:
	static const int LIMIT = 25;
	std::string _lname;
	char _fname[LIMIT];
public:
	Person() { _lname = ""; _fname[0] = '\0'; }
	Person(const std::string& ln, const char* fn = "Heyyou");
	void Show() const;
	void FormalShow() const;
};

#endif

//*******************************************************************************************

//person.cpp
//*******************************************************************************************

#include <iostream>
#include <string>
#include <cstring>
#include "Person.h"

Person::Person(const std::string& ln, const char* fn)
{
	_lname = ln;
	strcpy(_fname, fn);
}

void Person::Show() const
{
	std::cout << "Name : " << std::endl;
	std::cout << _fname << ' ' << _lname << std::endl;
}

void Person::FormalShow() const
{
	std::cout << "Fornmal name : " << std::endl;
	std::cout << _lname << ", " << _fname << std::endl;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include <string>
#include "Person.h"

int main()
{
	{
		using std::cout;
		using std::endl;

		Person one;
		one.Show();
		cout << endl;
		one.FormalShow();
		cout << endl;

		Person two("Smythecraft");
		two.Show();
		cout << endl;
		two.FormalShow();
		cout << endl;

		Person three("Dimwdiddy", "Sam");
		three.Show();
		cout << endl;
		three.FormalShow();
		cout << endl;
	}

	system("pause");
	return 0;
}

//*******************************************************************************************