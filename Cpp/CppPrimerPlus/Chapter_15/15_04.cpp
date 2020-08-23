
//sales.h
//*******************************************************************************************

#ifndef SALES_H
#define SALES_H

#include <stdexcept>
#include <string>
#include <iostream>

class Sales
{
public:
	enum { MONTHS = 12 };
	class bad_index : public std::logic_error
	{
	private:
		int bi;
	protected:
		int bi_val() const { return bi; }
	public:
		explicit bad_index(int ix, const std::string& s = "Index error in Sales object\n");
		void report() const { std::cout << "bad index : " << bi_val() << std::endl; }
		virtual ~bad_index() throw() {}
	};
	explicit Sales(int yy = 0);
	Sales(int yy, const double* gr, int n);
	virtual ~Sales() {}
	int Year() const { return year; }
	virtual double operator[](int i) const;
	virtual double& operator[](int i);
private:
	double gross[MONTHS];
	int year;
};

class LabeledSales : public Sales
{
public:
	class nbad_index : public Sales::bad_index
	{
	private:
		std::string lbl;
		const std::string& label_val() const { return lbl; }
	public:
		nbad_index(const std::string& lb, int ix, const std::string& s = "Index error in LabeledSales object\n");
		void report() const {
			std::cout << "Company : " << label_val() << std::endl;
			std::cout << "bad index : " << bad_index::bi_val() << std::endl;
		}
		virtual ~nbad_index() throw() {}
	};
	explicit LabeledSales(const std::string& lb = "none", int yy = 0);
	LabeledSales(const std::string& lb, int yy, const double* gr, int n);
	virtual ~LabeledSales() {}
	const std::string& Label() const { return label; }
	virtual double operator[](int i) const;
	virtual double& operator[](int i);
private:
	std::string label;
};

#endif

//*******************************************************************************************

//sales.cpp
//*******************************************************************************************

#include "sales.h"

using std::string;

Sales::bad_index::bad_index(int ix, const string& s) : std::logic_error(s), bi(ix) {}

Sales::Sales(int yy)
{
	year = yy;
	for (int i = 0; i < MONTHS; i++)
		gross[i] = 0;
}

Sales::Sales(int yy, const double* gr, int n)
{
	year = yy;
	int lim = (n < MONTHS ? n : MONTHS);
	int i;
	for (i = 0; i < lim; i++)
		gross[i] = gr[i];
	for (; i < MONTHS; i++)
		gross[i] = 0;
}

double Sales::operator[](int i) const
{
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}

double& Sales::operator[](int i)
{
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}

LabeledSales::nbad_index::nbad_index(const string& lb, int ix, const string& s) : Sales::bad_index(ix, s)
{
	lbl = lb;
}

LabeledSales::LabeledSales(const string& lb, int yy) : Sales(yy)
{
	label = lb;
}

LabeledSales::LabeledSales(const std::string& lb, int yy, const double* gr, int n) : Sales(yy, gr, n)
{
	label = lb;
}

double LabeledSales::operator[](int i) const
{
	if (i < 0 || i >= MONTHS)
		throw nbad_index(Label(), i);
	return Sales::operator[](i);
}

double& LabeledSales::operator[](int i)
{
	if (i < 0 || i >= MONTHS)
		throw nbad_index(Label(), i);
	return Sales::operator[](i);
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include "sales.h"

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	double vals1[12] =
	{
		1220, 1100, 1122, 2212, 1232, 2334,
		2884, 2393, 3302, 2922, 3002, 3544
	};
	double vals2[12] =
	{
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};
	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);

	cout << "First try block : " << endl;
	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (int i = 0; i < 12; i++)
		{
			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; i++)
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1." << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		bad.report();
	}
	cout << "\nNext try block : " << endl;
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "End of try block 2." << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		bad.report();
	}
	cout << "Done." << endl;

	system("pause");
	return 0;
}

//*******************************************************************************************