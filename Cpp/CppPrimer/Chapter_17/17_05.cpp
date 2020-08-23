/*

using matches = pair<vector<Sales_data>::size_type, pair<vector<Sales_data>::const_iterator, 
    vector<Sales_data>::const_iterator>>;

vector<matches> findBook(const vector<vector<Sales_data>>& files, const string& book)
{
    vector<matches> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it) 
    {
        auto found = equal_range(it->cbegin(), it->cend(), Sales_data(book),
            [](const Sales_data& sd1, const Sales_data& sd2) { return sd1.isbn() < sd2.isbn(); });
        if (found.first != found.second)
            ret.push_back(make_pair(it - files.cbegin(), make_pair(found.first, found.second)));
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
            os << "store " << store.first + 1 << " sales: "
                << accumulate(store.second.first, store.second.second,Sales_data(s)) << endl;
        }
        cout << "----" << endl;
    }
}

*/