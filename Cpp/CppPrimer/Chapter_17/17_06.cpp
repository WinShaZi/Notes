/*

struct Matches 
{
    friend class Sales_data;

    Matches(vector<Sales_data>::size_type i, vector<Sales_data>::const_iterator b, vector<Sales_data>::const_iterator e)
        : index(i), begin(b), end(e) {}

    vector<Sales_data>::size_type index;
    vector<Sales_data>::const_iterator begin;
    vector<Sales_data>::const_iterator end;
};

vector<Matches> findBook(const vector<vector<Sales_data>>& files, const string& book)
{
    vector<Matches> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it) 
    {
        auto found = equal_range(it->cbegin(), it->cend(), Sales_data(book),
            [](const Sales_data& sd1, const Sales_data& sd2) { return sd1.isbn() < sd2.isbn(); });
        if (found.first != found.second)
            ret.push_back(Matches(it - files.cbegin(), found.first, found.second));
    }
    return ret;

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
            os << "store " << store.index + 1 << " sales: "
                << accumulate(store.begin, store.end, Sales_data(s)) << endl;
        }
        cout << "----" << endl;
    }

*/