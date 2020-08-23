#include <iostream>
#include <string>

using namespace std;

class Person
{
private: 
	string name;
	string address;
public:
	Person() : name("none"), address("none") {}
};
 
int main()
{
	Person p;

	system("pause");
	return 0;
}