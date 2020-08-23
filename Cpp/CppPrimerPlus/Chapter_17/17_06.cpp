
//emp.h
//*******************************************************************************************

#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum classkind { Employee, Manager, Fink, Highfink };

class abstr_emp
{
private:
	string fname;
	string lname;
	string job;
public:
	abstr_emp();
	abstr_emp(const string& fn, const string& ln, const string& j);
	virtual void ShowAll() const;
	virtual void WriteAll(ofstream& fout) const;
	virtual void GetAll(ifstream& fin);
	virtual void SetAll();
	friend ostream& operator<<(ostream& os, const abstr_emp& e); 
};

class employee : virtual public abstr_emp
{
public:
	employee();
	employee(const string& fn, const string& ln, const string& j);
	virtual void ShowAll() const;
	virtual void WriteAll(ofstream& fout) const;
	virtual void GetAll(ifstream& fin);
	virtual void SetAll();
};

class manager : virtual public abstr_emp
{
private:
	int inchargeof;
protected:
	int InChargeOf() const { return inchargeof; }
	int& InChargeOf() { return inchargeof; }
public:
	manager();
	manager(const string& fn, const string& ln, const string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);
	virtual void ShowAll() const;
	virtual void WriteAll(ofstream& fout) const;
	virtual void GetAll(ifstream& fin);
	virtual void SetAll();
};

class fink : virtual public abstr_emp
{
private:
	string reportsto;
protected:
	const string ReportsTo() const { return reportsto; }
	string& ReportsTo() { return reportsto; }
public:
	fink();
	fink(const string& fn, const string& ln, const string& j, const string& rpo);
	fink(const abstr_emp& e, const string& rpo);
	fink(const fink& e);
	virtual void ShowAll() const;
	virtual void WriteAll(ofstream& fout) const;
	virtual void GetAll(ifstream& fin);
	virtual void SetAll();
};

class highfink : public manager, public fink
{
public:
	highfink();
	highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const string& rpo);
	highfink(const highfink& h);
	virtual void ShowAll() const;
	virtual void WriteAll(ofstream& fout) const;
	virtual void GetAll(ifstream& fin);
	virtual void SetAll();
};

#endif

//*******************************************************************************************

//emp.cpp
//*******************************************************************************************

#include "emp.h"

void abstr_emp::ShowAll() const
{
	cout << "First name: " << fname << endl;
	cout << "Last name: " << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::WriteAll(ofstream& fout) const
{
	fout << fname << endl;
	fout << lname << endl;
	fout << job << endl;
}

void abstr_emp::GetAll(ifstream& fin)
{
	fin >> fname >> lname >> job;
}

void abstr_emp::SetAll()
{
	cout << "Enter first name: ";
	cin >> fname;
	cout << "Enter last name: ";
	cin >> lname;
	cout << "Enter job:";
	cin >> job;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof is: " << inchargeof << endl;
}

void manager::WriteAll(ofstream& fout) const
{
	fout << Manager << endl;
	abstr_emp::WriteAll(fout);
	fout << inchargeof << endl;
}

void manager::GetAll(ifstream& fin)
{
	abstr_emp::GetAll(fin);
	fin >> inchargeof;
}

void manager::SetAll()
{

	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	cin >> inchargeof;
	cin.get();
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Reportsto is: " << reportsto << endl;
}

void fink::WriteAll(ofstream& fout) const
{
	fout << Fink << endl;
	abstr_emp::WriteAll(fout);
	fout << reportsto << endl;
}

void fink::GetAll(ifstream& fin)
{
	abstr_emp::GetAll(fin);
	fin >> reportsto;
}

void fink::SetAll()
{
	abstr_emp::SetAll();

	cout << "Enter the reportsto: ";
	cin >> reportsto;
}

void highfink::ShowAll() const
{
	manager::ShowAll();
	cout << "Reportsto is: " << fink::ReportsTo() << endl;
}

void highfink::WriteAll(ofstream& fout) const
{
	fout << Highfink << endl;
	abstr_emp::WriteAll(fout);
	fout << manager::InChargeOf() << endl;
	fout << fink::ReportsTo() << endl;
}

void highfink::GetAll(ifstream& fin)
{
	manager::GetAll(fin);
	fin >> fink::ReportsTo();
}

void highfink::SetAll()
{
	manager::SetAll();

	cout << "Enter the reportsto: ";
	string a;
	cin >> a;
	fink::ReportsTo() = a;
}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::WriteAll(ofstream& fout) const
{
	fout << Employee << endl;
	abstr_emp::WriteAll(fout);
}

void employee::GetAll(ifstream& fin)
{
	abstr_emp::GetAll(fin);
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

abstr_emp::abstr_emp() : fname("none"), lname("none"), job("none") {}

abstr_emp::abstr_emp(const string& fn, const string& ln, const string& j) : fname(fn), lname(ln), job(j) {}


ostream& operator<<(ostream& os, const abstr_emp& e)
{
	os << "First name: " << e.fname << endl;
	os << "Last name: " << e.lname << endl;
	os << "Job: " << e.job << endl;
	return os;
}

employee::employee() : abstr_emp() {}

employee::employee(const string& fn, const string& ln, const string& j) : abstr_emp(fn, ln, j) {}

manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const string& fn, const string& ln, const string& j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager& m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

fink::fink() : abstr_emp(), reportsto("none") {}

fink::fink(const string& fn, const string& ln, const string& j, const string& rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp& e, const string& rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink& e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

highfink::highfink() : abstr_emp(), manager(), fink() {}

highfink::highfink(const string& fn, const string& ln, const string& j,
	const string& rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const fink& f, int ico) : abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager& m, const string& rpo) : abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h) {}

//*******************************************************************************************

//mian.cpp
//*******************************************************************************************

#include "emp.h"

const char* file = "emp.txt";
const int MAX = 10;

int main()
{
	char ch;
	int i;

	abstr_emp* pc[MAX];
	ifstream fin;
	fin.open(file);

	if (!fin.is_open())
	{
		cerr << "Can't open \"" << file << "\" file" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Here are the contents of the " << file << " file : " << endl;
	int classtype;
	i = 0;
	while ((fin >> classtype).get(ch))
	{
		switch (classtype)
		{
		case Employee: pc[i] = new employee;
			break;
		case Manager:  pc[i] = new manager;
			break;
		case Fink:	   pc[i] = new fink;
			break;
		case Highfink: pc[i] = new highfink;
			break;
		}
		pc[i]->GetAll(fin);
		pc[i]->ShowAll();
	}
	fin.close();

	ofstream fout(file, ios::out | ios::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file" << endl;
		exit(EXIT_FAILURE);
	}

	int index = 0;
	cout << "Please choose the class you want to enter : " << endl;
	cout << "e for employee, m for manager, f for fink, h for highfink, q to quit" << endl;
	while (cin >> ch && index < MAX)
	{
		if (ch == 'q')
			break;
		switch (ch)
		{
		case 'e': pc[index] = new employee;
			break;
		case 'm': pc[index] = new manager;
			break;
		case 'f': pc[index] = new fink;
			break;
		case 'h': pc[index] = new highfink;
			break;
		}
		pc[index]->SetAll();
		index++;
		cout << "Please choose the class you want to enter : " << endl;
		cout << "e for employee, m for manager, f for fink, h for highfink, q to quit" << endl;
	}

	for (i = 0; i < index; i++)
		pc[i]->WriteAll(fout);
	fout.close();

	fin.clear();
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the contents of the " << file << " file : " << endl;
		int classtype;
		i = 0;
		while ((fin >> classtype).get(ch))
		{
			switch (classtype)
			{
			case Employee: pc[i] = new employee;
				break;
			case Manager:  pc[i] = new manager;
				break;
			case Fink:	   pc[i] = new fink;
				break;
			case Highfink: pc[i] = new highfink;
				break;
			default:break;
			}
			pc[i]->GetAll(fin);
			pc[i]->ShowAll();
		}
		fin.close();
	}
	cout << "Done.\n";
	return 0;
}

//*******************************************************************************************