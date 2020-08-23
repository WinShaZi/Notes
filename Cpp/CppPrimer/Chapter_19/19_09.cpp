#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{
	friend bool operator==(const Base&, const Base&);
public:
	Base() = default;
	Base(int i_) : i(i_) { }
protected:
	virtual bool equal(const Base&) const;
private:
	int i;
};

class Derived : public Base
{
public:
	Derived() = default;
	Derived(string s_, int i_) : s(s_), Base(i_) { }
protected:
	bool equal(const Base&) const;
private:
	string s;
};

bool operator==(const Base &lhs, const Base &rhs)
{
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Base::equal(const Base &rhs) const
{
	return this->i == rhs.i;
}

bool Derived::equal(const Base &rhs) const
{
	auto r = dynamic_cast<const Derived&>(rhs);
	return (this->s == r.s) && this->Base::equal(rhs);
}

int main()
{
	Base *pb1 = new Derived();
	Base *pb2 = new Derived();
	Base *pb3 = new Derived("a", 1);
	Base *pb4 = new Base();

	cout << boolalpha << (*pb1 == *pb2) << endl;
	cout << boolalpha << (*pb1 == *pb3) << endl;
	cout << boolalpha << (*pb1 == *pb4) << endl;

	int arr[10];
	Derived d;

	cout << typeid(42).name() << ", "
			  << typeid(arr).name() << ", "
			  << typeid(d).name() << ", "
			  << typeid(string).name() << ", "
			  << typeid(pb1).name() << ", "
			  << typeid(*pb1).name() << ", "
			  << typeid(*pb3).name() << endl;

	system("pause");
	return 0;
}