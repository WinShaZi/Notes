/*

Sales_data item = {"978-059035", 15, 29.98};
// 要使用这种初始化方式，要求类必须是聚合类。因此Sales_data类需要改成如下形式:
struct Sales_data
{
    std::string bookNo;
    unsigned int unit_sold;
    double revenue;
};

*/