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
	TextQuery(ifstream&);
	QueryResult query(const string&) const;

private:
	shared_ptr<vector<string>> input;
	map<string, shared_ptr<set<size_t>>> result;
};

class QueryResult
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(const string& s, shared_ptr<set<size_t>> set, shared_ptr<vector<string>> v)
		: word(s), LineNumlist(set), input(v) { }
private:
	string word;
	shared_ptr<set<size_t>> LineNumlist;
	shared_ptr<vector<string>> input;
};

TextQuery::TextQuery(ifstream& ifs) : input(new vector<string>)
{
	size_t LineN = 1;
	for (string line; getline(ifs, line); ++LineN)
	{
		input->push_back(line);
		istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear())
		{
			remove_copy_if(text.begin(), text.end(), back_inserter(word), [](char &c) { return ispunct(c); });
			auto& LNList = result[word];
			if (!LNList)
				LNList.reset(new set<size_t>);
			LNList->insert(LineN);
		}
	}
}

QueryResult TextQuery::query(const string& str) const
{
	static shared_ptr<set<size_t>> nodate(new set<size_t>);
	auto found = result.find(str);
	if (found == result.end())
		return QueryResult(str, nodate, input);
	else
		return QueryResult(str, found->second, input);
}

ostream& print(ostream& out, const QueryResult& qr)
{
	out << qr.word << " occurs " << qr.LineNumlist->size()
		<< (qr.LineNumlist->size() > 1 ? " times" : " time") << endl;
	for (auto i : *qr.LineNumlist)
		out << "\t(line " << i << ") " << qr.input->at(i) << endl;
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
	}
}

int main()
{
	ifstream infile("data");
	if (infile)
		runQueries(infile);
	else
		cerr << "Can't open \"data\"" << endl;

	infile.close();

	system("pause");
	return 0;
}