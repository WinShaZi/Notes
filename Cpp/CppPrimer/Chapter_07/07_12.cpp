/*

struct Sales_data;

std::istream& read (std::istream& is, Sales_data& item);

struct Sales_data

{

    std::string bookNo;

    unsigned units_sold = 0;

    double revenue = 0.0;

    Sales_data() = default;

    Sales_data(const std::string &s) : bookNo(s){}

    Sales_data(const std::string &s, unsigned n, double r) : bookNo(s), units_sold(n), revenue(r) {}

    Sales_data(std::istream& is){ read(is, *this); };

    std::string isbn() const { return bookNo; }

    Sales_data& combine (const Sales_data& rhs);

};

*/