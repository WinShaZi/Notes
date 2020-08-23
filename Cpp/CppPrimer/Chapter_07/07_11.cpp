/*

{

​    Sales_data() = default;

​    Sales_data(const std::string &s) : bookNo(s){}

​    Sales_data(const std::string &s, unsigned n, double r) : bookNo(s), units_sold(n), revenue(r) {}

​    Sales_data(std::istream& is);

}

Sales_data::Sales_data (std::istream& is)

{

​    read(is, *this);

}

{
    Sales_data item1;

​    print(std::cout, item1) << std::endl;

​    Sales_data item2("0-201-78345-X");

​    print(std::cout, item2) << std::endl;

​    Sales_data item3("0-201-78345-X", 3, 20.00);

​    print(std::cout, item3) << std::endl;

​    Sales_data item4(std::cin);

​    print(std::cout, item4) << std::endl;
}

*/