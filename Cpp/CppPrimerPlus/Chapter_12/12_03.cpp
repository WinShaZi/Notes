
//stock.h
//*******************************************************************************************

#ifndef STOCK_H_
#define STOCK_H_

#include <iostream>

class Stock
{
private:
	char *company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock();
	Stock(const char* co, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock& topval(const Stock& s) const;
	friend std::ostream& operator<<(std::ostream& os, const Stock& s);
};

#endif

//*******************************************************************************************

//stock.cpp
//*******************************************************************************************

#include <iostream>
#include <cstring>
#include "stock.h"

using namespace std;

Stock::Stock()
{
	company = new char[1];
	company[0] = '\0';
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr)
{
	company = new char[strlen(co) + 1];
	strcpy(company, co);
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< company << " shares set to 0." << endl;
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	delete[] company;
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted." << endl;
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares sold can't be negative. "
			<< "Transaction is aborted." << endl;
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have! "
			<< "Transaction is aborted." << endl;
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

std::ostream& operator<<(std::ostream& os, const Stock& s)
{
	using std::cout;
	using std::ios_base;
	
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	os << "Company : " << s.company
		<< "  Shares : " << s.shares << endl;
	os << "  Share Price : $" << s.share_val;
	
	cout.precision(2);
	os << "  Total Worth: $" << s.total_val << endl;

	
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);

	return os;
}

const Stock& Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}




//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "stock.h"

const int STKS = 4;

int main()
{
	{
		Stock stocks[STKS] = {
			Stock("NanoSmart", 12, 20.0),
			Stock("Boffo Objects", 200, 2.0),
			Stock("Monolithic Obelisks", 130, 3.25),
			Stock("Fleep Enterprises", 60, 6.5)
		};

		std::cout << "Stock holdings : " << std::endl;
		int st;
		for (st = 0; st < STKS; st++)
			std::cout << stocks[st];

		const Stock* top = &stocks[0];
		for (st = 1; st < STKS; st++)
			top = &top->topval(stocks[st]);

		std::cout << std::endl;
		std::cout << "Most valuable holding : " << std::endl;
		std::cout << *top;
	}

	system("pause");
	return 0;
}


//*******************************************************************************************