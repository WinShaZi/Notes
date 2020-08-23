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
	virtual void debug() const;
};

class Disc_quote : public Quote
{
protected:
	size_t min_quan = 0;
	size_t max_quan = 0;
	double discount = 0.0;
public:
	Disc_quote() = default;
	Disc_quote(const string &book, double price, size_t i_qty, size_t m_qty, double disc)
		: Quote(book, price), min_quan(i_qty), max_quan(m_qty), discount(disc) { }
	virtual double net_price(size_t n) const override = 0;
};

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double sales_price, size_t qty, double disc) 
		: Disc_quote(book, sales_price, qty, disc) { }
	virtual double net_price(size_t n) const override;
};

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