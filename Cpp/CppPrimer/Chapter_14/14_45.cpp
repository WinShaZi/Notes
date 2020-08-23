#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <functional>

using namespace std;

class Sales_data 
{
    friend istream& operator>>(istream&, Sales_data&);
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
    Sales_data(const string& s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data() : Sales_data("", 0, 0.0f) {}
    Sales_data(const string& s) : Sales_data(s, 0, 0.0f) {}
    Sales_data(istream& is);

    Sales_data& operator=(const string&);
    Sales_data& operator+=(const Sales_data&);
    explicit operator string() const { return bookNo; }
    explicit operator double() const { return avg_price(); }

    string isbn() const { return bookNo; }

private:
    inline double avg_price() const;

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream& operator>>(istream&, Sales_data&);
ostream& operator<<(ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

Sales_data::Sales_data(istream& is) : Sales_data()
{
    is >> *this;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream& operator>>(istream& is, Sales_data& item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

ostream& operator<<(ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data& Sales_data::operator=(const string& isbn)
{
    *this = Sales_data(isbn);
    return *this;
}

int main()
{
	Sales_data cp5("C++ Primer 5th", 4, 106.5);
    cout << cp5 << endl;
    cout << static_cast<string>(cp5) << endl;
    cout << static_cast<double>(cp5) << endl;

	system("pause");
	return 0;
}