#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<iterator>

using namespace std;
 
class TextQuery
{
public:
	typedef vector<string>::size_type line_no;
	void read_file(ifstream& is) { store_file(is); build_map(); }
	set<line_no>run_query(const string&) const;
	string text_line(line_no) const;
	line_no size() const { return lines_of_text.size(); }
private:
	void store_file(ifstream&);
	void build_map();
	vector<string> lines_of_text;
	map<string, set<line_no> > word_map;
};

void TextQuery::store_file(ifstream& is)
{
	string textline;

	while (getline(is, textline))
		lines_of_text.push_back(textline);
}

void TextQuery::build_map()
{
	for (line_no line_num = 0; line_num != lines_of_text.size(); ++line_num)
	{
		istringstream line(lines_of_text[line_num]);
		string word;

		while (line >> word)
			word_map[word].insert(line_num);
	}
}

set<TextQuery::line_no> TextQuery::run_query(const string& query_word) const
{
	map<string, set<line_no> > ::const_iterator  loc = word_map.find(query_word);
	if (loc == word_map.end())
		return set<line_no>();
	else
		return loc->second;
}

string TextQuery::text_line(line_no line)const
{
	if (line < lines_of_text.size())
		return lines_of_text[line];
	return "\0";
}

class Query_Base 
{
	friend class Query;
protected:
	typedef TextQuery::line_no line_no;
	virtual ~Query_Base() { }

private:
	virtual set<line_no> eval(const TextQuery&) const = 0;
	virtual ostream& display(ostream & = cout)const = 0;
};

class Query 
{
	friend Query operator ~(const Query&);
	friend Query operator |(const Query&, const Query&);
	friend Query operator &(const Query&, const Query&);
public:
	Query(const string&);
	Query(const Query& c) : q(c.q), use(c.use) { ++* use; }
	~Query() { decr_use(); }
	Query& operator=(const  Query&);
	set<TextQuery::line_no> eval(const TextQuery& t)const { return q->eval(t); }
	ostream& display(ostream& os) const { return q->display(os); }
private:
	Query(Query_Base* query) :q(query), use(new size_t(1)) { }
	Query_Base* q;
	size_t* use;
	void decr_use()
	{
		if (--*use == 0)
		{
			delete q;
			delete use;
		}
	}
};

inline Query& Query::operator =(const Query& rhs)
{
	++* rhs.use;
	decr_use();
	q = rhs.q;
	use = rhs.use;

	return *this;
}

inline ostream& operator<<(ostream& os, const Query& q)
{
	return q.display(os);
}

class  Word_Query : public Query_Base
{
	friend class Query;
private:
	Word_Query(const string& s) :query_word(s) { }
	string query_word;
	set<line_no>eval(const TextQuery& t)const { return t.run_query(query_word); }
	ostream& display(ostream& os) const { return os << query_word; }
};

inline Query::Query(const string& word) : q(new Word_Query(word)), use(new size_t(1)) { }

class NotQuery : public Query_Base
{
	friend Query operator~(const Query&);
	NotQuery(const Query& q) : query1(q) { }
	set<line_no> eval(const TextQuery&) const;
	ostream& display(ostream& os) const { return os << "~(" << query1 << ")"; }
	const Query query1;
};

class BinaryQuery : public Query_Base
{
protected:
	BinaryQuery(const Query& left, const Query& right, const string& op) :
		lhs(left), rhs(right), oper(op) { }
	ostream& display(ostream& os) const { return os << "(" << lhs << " " << oper << " " << rhs << ")"; }
	const Query lhs, rhs;
	const string oper;
};

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&") { }
	set<line_no> eval(const TextQuery&) const;
};

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "|") { }
	set<line_no> eval(const TextQuery&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs)
{
	return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query& lhs, const Query& rhs)
{
	return new OrQuery(lhs, rhs);
}

inline Query operator~(const Query& q)
{
	return new NotQuery(q);
}

set<TextQuery::line_no> NotQuery::eval(const TextQuery& file) const
{
	set<line_no> has_val = query1.eval(file);
	set<line_no> ret;
	for (line_no n = 0; n != file.size(); ++n)
		if (has_val.find(n) == has_val.end())
			ret.insert(n);

	return ret;
}

set<TextQuery::line_no> AndQuery::eval(const TextQuery& file) const
{
	set<line_no> left = lhs.eval(file);
	set<line_no> right = rhs.eval(file);
	set<line_no> ret;
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(ret, ret.begin()));

	return ret;
}

set<TextQuery::line_no> OrQuery::eval(const TextQuery& file) const
{
	set<line_no> right = rhs.eval(file);
	set<line_no> ret = lhs.eval(file);
	ret.insert(right.begin(), right.end());

	return ret;
}

void print_result(const set<TextQuery::line_no>& locs, const TextQuery& file)
{
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << " occurs " << size << (size > 1 ? "Times" : "Time") << endl;
	line_nums::const_iterator it = locs.begin();
	for (; it != locs.end(); ++it)
		cout << (*it) + 1 << "\t" << file.text_line(*it) << endl;
}

int main()
{
	ifstream is("data");
	TextQuery tq;
	tq.read_file(is);
	Query q = ~Query("the");
	set<TextQuery::line_no> locs = q.eval(tq);
	q.display(cout);
	print_result(locs, tq);

	system("pause");
	return 0;
}