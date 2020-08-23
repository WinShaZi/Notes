/*

class Sales_data
{
    friend std::istream& read (std::istream& is, Sales_data& item);
    friend std::ostream& print (std::ostream& os, const Sales_data& item);
    friend Sales_data& add(Sales_data* item1, Sales_data& item2);
public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s){}
    Sales_data(const std::string &s, unsigned n, double r) : bookNo(s), units_sold(n), revenue(r) {}
    Sales_data(std::istream& is){ read(is, *this); };
    std::string isbn() const { return bookNo; }
    Sales_data& combine (const Sales_data& rhs);
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream& read (std::istream& is, Sales_data& item);
std::ostream& print (std::ostream& os, const Sales_data& item);
Sales_data& add(Sales_data* item1, Sales_data& item2);

*/