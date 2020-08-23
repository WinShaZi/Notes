#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <numeric>

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
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
       << item.avg_price();
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

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

using matches =
    tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>;

vector<matches> findBook(const vector<vector<Sales_data>>& files, const string& book)
{
    vector<matches> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it) 
	{
        auto found = equal_range(it->cbegin(), it->cend(), Sales_data(book), 
            [](const Sales_data& sd1, const Sales_data& sd2) { return sd1.isbn() < sd2.isbn(); });
        if (found.first != found.second)
            ret.push_back(
                make_tuple(it - files.cbegin(), found.first, found.second));
    }
    return ret;
}

void reportResults(istream& in, ostream& os, const vector<vector<Sales_data>>& files)
{
    string s;
    while (cout << "Enter the book ISBN to look for: ", in >> s) 
    {
        auto trans = findBook(files, s);
        if (trans.empty()) 
        {
            cout << s << " not found in any stores." << endl;
            continue;
        }
        for (auto&& store : trans) 
        {
            os << "store " << get<0>(store) + 1 << " sales: "
               << accumulate(get<1>(store), get<2>(store), Sales_data())
               << endl;
        }
        cout << "----" << endl;
    }
}

vector<Sales_data> build_store(const string& s)
{
    vector<Sales_data> ret;
    ifstream is(s);
    Sales_data item;
    while (is >> item) 
		ret.push_back(item);
    sort(ret.begin(), ret.end(),
         [](const Sales_data& lhs, const Sales_data& rhs) { return lhs.isbn() < rhs.isbn(); });
    return ret;
}

int main()
{
	vector<vector<Sales_data>> files;
    for (int cnt = 1; cnt <= 4; ++cnt)
        files.push_back(build_store("_data" + to_string(cnt)));

    reportResults(cin, cout, files);

	system("pause");
	return 0;
}