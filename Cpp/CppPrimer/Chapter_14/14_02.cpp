/*

istream& operator>> (istream& is, Sales_data& s)
{
    double price;
    is >> s.bookNo >> s.units_sold >> price;
    s.revenue = price * s.units_sold;
    return is;
}

ostream& operator<< (ostream& os, Sales_data& s)
{

    os << s.isbn() << "\t" << s.units_sold << "\t" << s.revenue << "\t" << s.avg_price() << endl;
}

Sales_data& operator+ (const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data ret(lhs);
    ret += rhs;
    return ret;
}

Sales_data& Sales_data::operator+= (const Sales_data& s)
{
    units_sold += s.units_sold;
    revenue += s.revenue;
    return *this;
}

*/