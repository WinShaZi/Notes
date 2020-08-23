/*

istream& operator>>(istream& is, Sales_data& s)
{
    double price;

    is >> s.bookNo >> s.units_sold >> price;
    if (is) 
    {
        s.revenue = price * s.units_sold;
    }
    else 
    {
        s = Sales_data();
    }
    
    return is;
}

*/