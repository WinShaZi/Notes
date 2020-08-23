/*

bool compareIsbn(const Sales_data& sale1, const Sales_data& sale2)
{
    return sale1.isbn().size() > sale2.isbn().size();
}

vector<Sales_data> sale_vec;
string bookNo = "";
for (int i = 0; i < 5; i++)
{
    bookNo += "s";
    cout << bookNo << endl;
    sale_vec.push_back(Sales_data(bookNo));
}

for (auto i : sale_vec) 
{
    print(cout, i);
}

sort(sale_vec.begin(), sale_vec.end(), compareIsbn);

for (auto i : sale_vec)
{
    print(cout, i);
}

*/