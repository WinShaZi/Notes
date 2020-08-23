#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee
{
public:
	Employee() = default;
	Employee(const string &s)
	{
		name = s;
		++employee_number;
		cout << name << ' ' << employee_number << endl;
	}
    string name;
    static int employee_number;
};

int Employee::employee_number = 0; 

int main()
{
	Employee a("A");

	system("pause");
	return 0;
}