/*

class Person
{
private:
	string name;
	string address;
public:
	Person();
	void Show() const;
	friend istream &read(istream &is, Person &pr);
	friend ostream &print(ostream &os, const Person &pr);
};


Person::Person() : name("none"), address("none") {}

void Person::Show() const
{
	cout << "Name : " << name << endl;
	cout << "Address : " << address << endl;
}

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