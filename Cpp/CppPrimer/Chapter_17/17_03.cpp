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

using namespace std;

using line_no = vector<string>::size_type;
using query_result = tuple<string, shared_ptr<set<line_no>>, shared_ptr<vector<string>>>;

class TextQuery 
{
public:
    TextQuery(ifstream&);
    query_result query(const string&) const;

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

ostream& print(ostream&, const query_result&);

TextQuery::TextQuery(ifstream& is) : file(new vector<string>)
{
    string txt;
    while (getline(is, txt)) 
	{
        file->push_back(txt);
        int n = file->size() - 1;
        txt.erase(remove_if(txt.begin(), txt.end(), ::ispunct), txt.end());
        istringstream line(txt);
        string word;
        while (line >> word) 
		{
            auto& lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

query_result TextQuery::query(const string& sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end()) return make_tuple(sought, nodata, file);
    return make_tuple(sought, loc->second, file);
}

string make_plural(size_t ctr, string const& word, string const& ending)
{
    return (ctr > 1) ? word + ending : word;
}

ostream& print(ostream& os, const query_result& qr)
{
    os << get<0>(qr) << " occurs " << get<1>(qr)->size() << " "
       << make_plural(get<1>(qr)->size(), "time", "s") << endl;

    for (auto num : *get<1>(qr))
        os << "\t(line " << num + 1 << ") " << *(get<2>(qr)->begin() + num)
           << endl;
    return os;
}

void runQueries(ifstream& infile)
{
    TextQuery tq(infile);
    while (true) 
	{
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
       print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream file("data");
    runQueries(file);

	system("pause");
	return 0;
}