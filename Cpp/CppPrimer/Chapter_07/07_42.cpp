/*

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string name;
	string address;
public:
	Person();
	Person(const string &stn);
	Person(const string &stn, const string &sta);
	void Show() const;
	friend istream &read(istream &is, Person &pr);
	friend ostream &print(ostream &os, const Person &pr);
};


Person::Person() : name("none"), address("none") {}

Person::Person(const string &st)
{
	name = st;
}

Person::Person(const string &st1, const string &st2) : Person(st1) {}

istream &read(istream &is, Person &pr)
{
	is >> pr.name >> pr.address;

	return is;
}

ostream &print(ostream &os, const Person &pr)
{
	os << "Name : " << pr.name << endl;
	os << "Address : " << pr.address << endl;

	return os;
}

*/