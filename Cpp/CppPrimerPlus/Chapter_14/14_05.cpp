
//emp.h
//*******************************************************************************************

#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>

using namespace std;

class abstr_emp
{
private:
	string fname;
	string lname;
	string job;
public :
	abstr_emp();
	abstr_emp(const string& fn, const string& ln, const string& j);
	abstr_emp(const abstr_emp& e);
	virtual void ShowAll()const;
	virtual void SetAll();
	friend ostream& operator<<(ostream& os, const abstr_emp& e);
};

class employee :public abstr_emp
{
public:
	employee();
	employee(const string& fn, const string& ln, const string& j);
	virtual void ShowAll()const;
	virtual void SetAll();
};

class manager :virtual public abstr_emp
{
private:
	int inchargeof;
protected:
	int InChargeof()const { return inchargeof; }
	int& InChargeof() { return inchargeof; }
public:
	manager();
	manager(const string& fn, const string& ln, const string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);
	virtual void ShowAll()const;
	virtual void SetAll();
};

class fink :virtual public abstr_emp
{
private:
	string reportsto;
protected:
	const string Reportsto()const { return reportsto; }
	string& Reportsto() { return reportsto; }
public:
	fink();
	fink(const string& fn, const string& ln, const string& j, const string& rpo);
	fink(const abstr_emp& e, const string& rpo);
	fink(const fink& f);
	virtual void ShowAll()const;
	virtual void SetAll();
};

class highfink :public manager, public fink
{
public:
	highfink();
	highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const abstr_emp& e, const string& rpo, int ico);
	highfink(const manager& m, const string& rpo);
	highfink(const highfink& h);
	virtual void ShowAll()const;
	virtual void SetAll();
};

#endif

//*******************************************************************************************

//emp.cpp
//*******************************************************************************************

#include "emp.h"

abstr_emp::abstr_emp()
{
	fname = "none";
	lname = "none";
	job = "none";
}

abstr_emp::abstr_emp(const string& fn, const string& ln, const string& j)
{
	fname = fn;
	lname = ln;
	job = j;
}

abstr_emp::abstr_emp(const abstr_emp& e)
{
	fname = e.fname;
	lname = e.lname;
	job = e.job;
}

void abstr_emp::ShowAll()const
{
	cout << "First name : " << fname << endl;
	cout << "Last name : " << lname << endl;
	cout << "Job : " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Iput a first name : ";
	getline(cin, fname);
	cout << "Input a last name : ";
	getline(cin, lname);
	cout << "Input a job : ";
	getline(cin, job);
}

ostream& operator<<(ostream& os, const abstr_emp& e)
{
	cout << e.fname << ", " << e.lname << ", " << e.job << endl;

	return os;
}

employee::employee() :abstr_emp() {}

employee::employee(const string& fn, const string& ln, const string& j) : abstr_emp(fn, ln, j) {}

void employee::ShowAll()const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager() :abstr_emp(), inchargeof(0) {}

manager::manager(const string& fn, const string& ln, const string& j, int ico) 
	: abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof : " << inchargeof << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Input the value of inchargeof : ";
	while (!(cin >> inchargeof))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Input the value of inchargeof : ";
	}
	while (cin.get() != '\n');
}

fink::fink() :abstr_emp() {}

fink::fink(const string& fn, const string& ln, const string& j, const string& rpo) 
	: abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp& e, const string& rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink& f) : abstr_emp(f) {}

void fink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Reportsto : " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Input Reportsto : ";
	getline(cin, reportsto);
}

highfink::highfink() :abstr_emp(), manager(), fink() {}

highfink::highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico) 
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const fink& f, int ico) : abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const abstr_emp& e, const string& rpo, int ico) 
	: abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const manager& m, const string& rpo) : abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof : " << InChargeof() << endl;
	cout << "Reportsto : " << Reportsto() << endl;
}

void highfink::SetAll()
{
	int ico;
	string rpo;

	abstr_emp::SetAll();
	cout << "Input the value of inchargeof : ";
	while (!(cin >> ico))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Input the value of inchargeof : ";
	}
	while (cin.get() != '\n');
	cout << "Input Reportsto : ";
	getline(cin, rpo);
	manager::InChargeof() = ico;
	fink::Reportsto() = rpo;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include "emp.h"

int main()
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	cout << endl;
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	cout << endl;
	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	cout << endl;
	highfink hf(ma, "Curly Kew");
	hf.ShowAll();
	cout << endl;
	cout << "Press a key for next phase : " << endl;
	cin.get();
	highfink hf2;
	hf2.SetAll();

	cout << "Using an abstr_emp * pointer : ";
	abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();

	system("pause");
	return 0;
}

//*******************************************************************************************