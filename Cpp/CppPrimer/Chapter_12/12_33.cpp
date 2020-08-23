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
#include <initializer_list>

using namespace std;

class ConstStrBlobPtr;
class StrBlob 
{
public:
    using size_type = vector<string>::size_type;
    friend class ConstStrBlobPtr;

    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string& t) { data->push_back(t); }
    void pop_back()
    {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    string& front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    string& back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const string& front() const
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const string& back() const
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    void check(size_type i, const string& msg) const
    {
        if (i >= data->size()) throw out_of_range(msg);
    }

private:
    shared_ptr<vector<string>> data;
};

class ConstStrBlobPtr 
{
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    bool operator!=(ConstStrBlobPtr& p) { return p.curr != curr; }
    const string& deref() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    ConstStrBlobPtr& incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    shared_ptr<vector<string>> check(size_t i, const string& msg) const
    {
        auto ret = wptr.lock();
        if (!ret) 
            throw runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) 
            throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
    return ConstStrBlobPtr(*this, data->size());
}


class QueryResult;
class TextQuery
{
public:
    TextQuery(ifstream& ifs);
    QueryResult query (const string& word) const;

private:
    StrBlob sp_text;
    map<string, shared_ptr<set<StrBlob::size_type>>> sp_dictionary;
};

class QueryResult
{
public:
     friend ostream& print (ostream&, const QueryResult&);
public:
    set<StrBlob::size_type>::iterator begin() const { return lines->begin(); }
    set<StrBlob::size_type>::iterator end() const { return lines->end(); }
    shared_ptr<StrBlob> getFile() const { return make_shared<StrBlob>(file); }
    QueryResult(const string& s, shared_ptr<set<StrBlob::size_type>> sp_set, StrBlob sb) 
        : sought (s), lines (sp_set), file (sb) {}

private:
    string sought;
    shared_ptr<set<StrBlob::size_type>> lines;
    StrBlob file;
};

TextQuery::TextQuery(ifstream& ifs)
{
    string text;
    StrBlob::size_type n = 0;
    while (getline(ifs, text)) 
    {
        sp_text.push_back(text);
        n = sp_text.size() - 1;
        istringstream line (text);
        string word;
        while (line >> word) 
        {
            auto &lines = sp_dictionary[word];

            if (!lines) 
            {
                lines.reset (new set<StrBlob::size_type>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string& word) const
{
    static shared_ptr<set<StrBlob::size_type>> nodata (new set<StrBlob::size_type>);
    auto loc = sp_dictionary.find(word);

    if (loc == sp_dictionary.end()) 
    {
        return QueryResult(word, nodata, sp_text);
    }
    else 
    {
        return QueryResult(word, loc->second, sp_text);
    }
}

ostream& print(ostream& os, const QueryResult& qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " times." << endl;

    for (auto iter = qr.begin(); iter != qr.end(); ++ iter) 
    {
        ConstStrBlobPtr p (*qr.getFile(), *iter);
        os << "\t(line " << *iter+1 << ") " << p.deref() << endl;
    }

    return os;
}

void runQueries (ifstream &infile)
{
    TextQuery tq (infile);

    while (true) {
        cout << "Enter word to look for, or q to quit: ";
        string s;

        if (!(cin >> s) || s == "q") break;
            print (cout, tq.query(s)) << endl;
    }
}


int main()
{
	ifstream infile("data");

	runQueries(infile);
	
	system("pause");
	return 0;
}