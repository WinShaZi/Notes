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

class Bulk_quote : public Quote
{
private:
	size_t min_qty;
	size_t max_qty;
	double discount;
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double sales_price, size_t i_qty, size_t a_qty, double disc) 
		: Quote(book, sales_price), min_qty(i_qty), max_qty(a_qty), discount(disc) { }
	virtual ~Bulk_quote() = default;
	virtual double net_price(size_t n) const;
	virtual void debug() const override;
};

void Quote::debug() const
{
	cout << "BookNo : " << bookNo << endl;
	cout << "Price : " << price << endl;
}

void Bulk_quote::debug() const
{
	Quote::debug();
	cout << "Min_qty : " << min_qty << endl;
	cout << "Max_qty : " << max_qty << endl;
}

double Bulk_quote::net_price(size_t n) const
{
	if (n >= min_qty && n <= max_qty)
		return n * (1 - discount)  * price;
	else if (n > max_qty)
		return (n - max_qty * discount) * price;
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
	Quote q("C++ Primer", 128.0);
	Bulk_quote b("C++ Primer Plus", 99.0, 10, 20, 0.5);

	print_total(cout, q, 8);
	print_total(cout, b, 30);

	q.debug();
	b.debug();

	system("pause");
	return 0;
}