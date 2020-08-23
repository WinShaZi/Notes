#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <memory>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std;

class QueryResult;
class TextQuery 
{
public:
    using LineNo = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> input;
    map<string, shared_ptr<set<LineNo>>> result;
};

class QueryResult 
{
    friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(const string& s, shared_ptr<set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v)
        : word(s), nos(set), input(v) { }
private:
    string word;
    shared_ptr<set<TextQuery::LineNo>> nos;
    shared_ptr<vector<string>> input;
};

TextQuery::TextQuery(ifstream& ifs) : input(new vector<string>)
{
    LineNo lineNo{0};
    for (string line; getline(ifs, line); ++lineNo) {
        input->push_back(line);
        istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) 
		{
            remove_copy_if(text.begin(), text.end(), back_inserter(word), [](char &c) { return ispunct(c); });
            auto& nos = result[word];
            if (!nos) nos.reset(new set<LineNo>);
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const string& str) const
{
    static shared_ptr<set<LineNo>> nodate(new set<LineNo>);
    auto found = result.find(str);
    if (found == result.end())
        return QueryResult(str, nodate, input);
    else
        return QueryResult(str, found->second, input);
}

ostream& print(ostream& out, const QueryResult& qr)
{
    out << qr.word << " occurs " << qr.nos->size()
        << (qr.nos->size() > 1 ? " times" : " time") << endl;
    for (auto i : *qr.nos)
        out << "\t(line " << i + 1 << ") " << qr.input->at(i) << endl;
    return out;
}

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);

	while (true)
	{
		cout << "Input word to look for, or q to quit : ";

		string s;

		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s));
	};
}

int main()
{
	ifstream infile("data");

	runQueries(infile);
	
	system("pause");
	return 0;
}