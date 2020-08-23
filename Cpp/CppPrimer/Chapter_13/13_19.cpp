/*

不需要拷贝控制成员，因为每个雇员的ID都不同，不能有两个id和name都相同的雇员

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
	Employee(const Employee & e) = default;
	Employee & operator=(Employee & e) = default;
    string name;
    static int employee_number;
};

*/