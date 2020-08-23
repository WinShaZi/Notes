#include <iostream>
#include <string>

using namespace std;

class Quote
{
private:
	string bookNo;
protected:
	double price = 0.0;
public:
	Quote() = default;
	Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) { }
	virtual ~Quote() = default;
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }
};

class Bulk_quote : public Quote
{
private:
	size_t min_qty;
	double discount;
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double sales_price, size_t qty, double disc) 
		: Quote(book, sales_price), min_qty(qty), discount(disc) { }
	virtual ~Bulk_quote() = default;
	virtual double net_price(size_t n) const;
};

double Bulk_quote::net_price(size_t n) const
{
	if (n >= min_qty)
		return n * (1 - discount)  * price;
	else
		return n * price;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN : " << item.isbn() << " # sold : " << n << " total : " << ret << endl;

	return ret;
}

int main()
{


	system("pause");
	return 0;
}