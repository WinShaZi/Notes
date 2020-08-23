#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Cpmv
{
public:
	struct Info
	{
		string qcode;
		string zcode;
	};
private:
	Info* pi;
public:
	Cpmv();
	Cpmv(string q, string z);
	Cpmv(const Cpmv& cp);
	Cpmv(Cpmv&& mv)noexcept;
	~Cpmv();
	Cpmv& operator=(const Cpmv& cp);
	Cpmv& operator=(Cpmv&& mv)noexcept;
	Cpmv operator+(const Cpmv& obj)const;
	void Display()const;
};

int main()
{
	Cpmv temp;
	cout << "Object 0 : " << endl;
	temp.Display();

	Cpmv temp1("number one", "number two");
	cout << "Object 1 : " << endl;
	temp1.Display();

	Cpmv temp2(temp);
	cout << "Object 2 : " << endl;
	temp2.Display();

	cout << "Object 3 = Object 1 : " << endl;
	Cpmv temp3;
	temp3 = temp1;
	cout << "Object 3 : " << endl;
	temp3.Display();
	cout << "Object 1 : " << endl;
	temp1.Display();

	cout << "Object 4 = move(Obejct 3): " << endl;
	Cpmv temp4;
	temp4 = move(temp3);
	cout << "Object 4 : " << endl;
	temp4.Display();
	cout << "Object 3 : " << endl;
	temp3.Display();

	cout << "Obejct 5 = Object 3 + Obejct 4 : " << endl;
	Cpmv temp5 = temp3 + temp4;
	cout << "Obejct 5 : " << endl;
	temp5.Display();

	system("pause");
	return 0;
}

Cpmv::Cpmv() 
{
	pi = new Info;
	pi->qcode = "none";
	pi->zcode = "none";
	cout << "Default success!" << endl;
}

Cpmv::Cpmv(string q, string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
	cout << "Parameter success！" << endl;
}

Cpmv::Cpmv(const Cpmv& cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	cout << "Copy success！" << endl;
}

Cpmv::Cpmv(Cpmv&& mv)noexcept
{
	pi = new Info;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "qcode";
	mv.pi->zcode = "zcode";
	cout << "Move success!" << endl;
}

Cpmv::~Cpmv()
{
	delete pi;
	cout << "Delete success!" << endl;
}

Cpmv& Cpmv::operator=(const Cpmv& cp) 
{
	if (this == &cp)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	cout << "Copy assignment operator success！" << endl;

	return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& mv)noexcept
{
	if (this == &mv)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "qcode";
	mv.pi->zcode = "zcode";
	cout << "Move assignment operator success!" << endl;

	return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj)const
{
	Cpmv sum;
	sum.pi->qcode = pi->qcode + obj.pi->qcode;
	sum.pi->zcode = pi->zcode + obj.pi->zcode;
	cout << "Plus operator success" << endl;

	return sum;
}

void Cpmv::Display()const
{
	cout << "qcode: " << pi->qcode << endl;
	cout << "zcode: " << pi->zcode << endl << endl;
}