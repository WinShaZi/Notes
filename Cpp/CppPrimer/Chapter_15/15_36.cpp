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
	LineNo lineNo{ 0 };
	for (string line; getline(ifs, line); ++lineNo) {
		input->push_back(line);
		istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear())
		{
			remove_copy_if(text.begin(), text.end(), back_inserter(word), [](char& c) { return ispunct(c); });
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

class Query_base
{
    friend class Query;
protected:
    using line_no = TextQuery::LineNo;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval (const TextQuery& ) const = 0;
    virtual string rep() const = 0;
};

class WordQuery : public Query_base
{
    friend class Query;
private:
    WordQuery(const string& s) : query_word(s)
    {
        cout << "WordQuery constructor. s = "  << s << endl;
    }
    QueryResult eval (const TextQuery& t) const
    {
        return t.query(query_word);
    }
    string rep() const
    {
        cout << "WordQuery::rep()" << endl;
        return query_word;
    }
    string query_word;
};

class Query
{
    friend Query operator~ (const Query &);
    friend Query operator| (const Query&, const Query&);
    friend Query operator& (const Query&, const Query&);
public:
    Query (const string& s) : q (new WordQuery(s))
    {
        cout << "Query constructor. s = "  << s << endl;
    }
    QueryResult eval(const TextQuery &t) const
    {
        return q->eval(t);
    }
    string rep () const
    {
        cout << "Query::rep()" << endl;
        return q->rep();
    }
private:
    Query (shared_ptr<Query_base> query) : q(query) {}
    shared_ptr<Query_base> q;
};

ostream& operator<< (ostream& os, Query& query)
{
    cout << "operator<<::rep()" << endl;
    return os << query.rep();
}

class NotQuery : public Query_base
{
    friend Query operator~(const Query&);
    NotQuery(const Query& q)  : query(q)
    {
        cout << "NotQuery constructor." << endl;
    }
    QueryResult eval (const TextQuery& ) const { }
    string rep() const override
    {
        cout << "NotQuery::rep()" << endl;
        return "~(" + query.rep() + ")";
    }
    Query query;
};

inline Query operator~(const Query& operand)
{
    return shared_ptr<Query_base> (new NotQuery(operand));
}

class BinaryQuery:public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query& r, string s):
        lhs(l), rhs(r), opSym(s)
    {
        cout << "BinaryQuery constructor." << endl;
    }
    string rep() const
    {
        cout << "BinaryQuery::rep()" << endl;
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    string opSym;
};

class AndQuery : public BinaryQuery
{
    friend Query operator& (const Query&, const Query&);
    AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&")
    {
        cout << "AndQuery constructor." << endl;
    }
    QueryResult eval(const TextQuery& ) const { }
};

inline Query operator& (const Query& lhs, const Query& rhs)
{
    return shared_ptr<Query_base> (new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery
{
    friend Query operator| (const Query&, const Query&);
    OrQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "|")
    {
        cout << "OrQuery constructor." << endl;
    }
    QueryResult eval(const TextQuery& ) const { }
};

inline Query operator| (const Query& lhs, const Query& rhs)
{
    return shared_ptr<Query_base> (new OrQuery(lhs, rhs));
}

int main()
{
    Query q = Query("firey") & Query("bird") | Query("wind");
    cout << q << endl;

    system("pause");
    return 0;
}