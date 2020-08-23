
//String.h
//*******************************************************************************************

#ifndef STRING_H_
#define STRING_H_

#include <iostream>

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String(const char* s);
	String();
	String(const String& st);
	~String();
	String& operator=(const String& st);
	String& operator=(const char* s);

	char& operator[](int i);
	const char& operator[](int i) const;
	void stringlow();
	void stringup();
	int has(char c) const;

	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend String operator+(const String& st1, const String& st2);
	friend std::ostream& operator<<(std::ostream& os, const String& st);
	friend std::istream& operator>>(std::istream& is, String& st);
};

#endif

//*******************************************************************************************

//String.cpp
//*******************************************************************************************

#include <cstring>
#include <cctype>
#include "String.h"

using std::cout;
using std::endl;

int String::num_strings = 0;

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;
}

String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;

	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);

	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);

	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

void String::stringlow()
{
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
}

void String::stringup()
{
	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
}

int String::has(char c) const
{
	int count = 0;

	for (int i = 0; i < len; i++)
		if (str[i] == c)
			count++;

	return count;
}

bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

String operator+(const String& st1, const String& st2)
{
	String s;

	s.len = st1.len + st2.len;
	s.str = new char[s.len + 1];
	strcpy(s.str, st1.str);
	strcat(s.str, st2.str);

	return s;
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;

	return os;
}

std::istream& operator>>(std::istream& is, String& st)
{
	char temp[String::CINLIM];

	is.getline(temp, String::CINLIM);
	if (is)
		st = temp;

	return is;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name : ";
	String s3;

	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << endl;

	s2 = s2 + s1;
	s2.stringup();
	cout << "The string : " << endl;
	cout << s2 << endl;
	cout << "contains " << s2.has('A')
		<< " 'A' characters in it." << endl;

	s1 = "red";
	String rgb[3] = { String(s1), String("green"), String("blue") };
	cout << "Enter the name of a primary color for mixing light : ";

	String ans;

	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i])
			{
				cout << "That's right!" << endl;
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!" << endl;
	}
	cout << "Bye" << endl;

	system("pause");
	return 0;
}

//*******************************************************************************************