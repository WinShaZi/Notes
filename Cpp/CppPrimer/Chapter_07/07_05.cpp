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
	void Show() const;
};


Person::Person() : name("none"), address("none") {}

void Person::Show() const
{
	cout << "Name : " << name << endl;
	cout << "Address : " << address << endl;
}
 
int main()
{
	Person P;

	P.Show();

	system("pause");
	return 0;
}