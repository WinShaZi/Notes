#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <set>

using namespace std;

class Quote
{
private:
	string bookNo;
protected:
	double price = 0.0;
public:
	Quote() = default;
	Quote(const Quote &quote) : bookNo(quote.bookNo), price(quote.price) { cout << "Quote" << endl; }
	Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) { }
	virtual ~Quote() = default;
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }
	virtual Quote * clone() const & { return new Quote(*this); }
	virtual Quote * clone() && { return new Quote(move(*this)); }
};

class Disc_quote : public Quote
{
protected:
	size_t min_quan = 0;
	size_t max_quan = 0;
	double discount = 0.0;
public:
	Disc_quote() = default;
	Disc_quote(const Disc_quote &dq) : Quote(dq), 
		min_quan(dq.min_quan), max_quan(dq.max_quan), discount(dq.discount) { cout << "Disc_quote" << endl; }
	Disc_quote(const string &book, double price, size_t i_qty, size_t m_qty, double disc)
		: Quote(book, price), min_quan(i_qty), max_quan(m_qty), discount(disc) { }
	virtual double net_price(size_t n) const override = 0;
};

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) { cout << "Bulk_quote" << endl; }
	Bulk_quote(const string &book, double sales_price, size_t i_qty, size_t m_qty, double disc) 
		: Disc_quote(book, sales_price, i_qty, m_qty, disc) { }
	virtual double net_price(size_t n) const override;
};

class Basket
{
private:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs)
    { return lhs->isbn() < rhs->isbn(); }
    multiset<shared_ptr<Quote>, decltype(compare) *> items{compare};
public:
    void add_item(const shared_ptr<Quote> &sales)
    { items.insert(sales); }
    double total_receipt (ostream &) const;
};

double Bulk_quote::net_price(size_t n) const
{
	if (n >= min_quan && n <= max_quan)
		return n * (1 - discount)  * price;
	else if (n > max_quan)
		return (n - max_quan * discount) * price;
	else 
		return n * price;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN : " << item.isbn() << " # sold : " << n << " total : " << ret << endl;

	return ret;
}

double Basket::total_receipt(ostream &os) const
{
	double sum = 0;

	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
		sum += print_total(os, **iter, items.count(*iter));
	os << "Total Sale : " << sum << endl;

	return sum;
}

int main()
{
	

	system("pause");
	return 0;
}