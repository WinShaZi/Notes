#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory>
#include <initializer_list>
#include <sstream>
#include <map>
#include <set>
#include <fstream>
#include <cctype>

using namespace std;

class StrVec 
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec(initializer_list<string>);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }

    string& at(size_t pos) { return *(elements + pos); }
    const string& at(size_t pos) const { return *(elements + pos); }

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const string&);

private:
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    void reallocate();
    void alloc_n_move(size_t new_cap);
    void range_initialize(const string*, const string*);

private:
    string* elements;
    string* first_free;
    string* cap;
    allocator<string> alloc;
};

void StrVec::push_back(const string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements) 
    {
        for_each(elements, first_free, [this](string &p) { alloc.destroy(&p); });
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::range_initialize(const string* first, const string* last)
{
    auto newdata = alloc_n_copy(first, last);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec& rhs)
{
    range_initialize(rhs.begin(), rhs.end());
}

StrVec::StrVec(initializer_list<string> il)
{
    range_initialize(il.begin(), il.end());
}

StrVec::~StrVec()
{
    free();
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t new_cap)
{
    if (new_cap <= capacity()) return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
    resize(count, string());
}

void StrVec::resize(size_t count, const string& s)
{
    if (count > size()) 
    {
        if (count > capacity()) reserve(count * 2);
        for (size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, s);
    }
    else if (count < size()) 
    {
        while (first_free != elements + count) alloc.destroy(--first_free);
    }
}

class QueryResult;
class TextQuery 
{
public:
    TextQuery(ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<StrVec> input;
    map<string, shared_ptr<set<size_t>>> result;
};

class QueryResult 
{
public:
    friend ostream& print(ostream&, const QueryResult&);

public:
    QueryResult(const string& s, shared_ptr<set<size_t>> set, shared_ptr<StrVec> v)
        : word(s), nos(set), input(v) { }
private:
    string word;
    shared_ptr<set<size_t>> nos;
    shared_ptr<StrVec> input;
};

ostream& print(ostream&, const QueryResult&);

TextQuery::TextQuery(ifstream& ifs) : input(new StrVec)
{
    size_t lineNo = 0;
    for (string line; getline(ifs, line); ++lineNo)
    {
        input->push_back(line);
        istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) 
        {
            remove_copy_if(text.begin(), text.end(),
                                back_inserter(word), [](char &c) { return ispunct(c); });
            auto& nos = result[word];
            if (!nos) nos.reset(new set<size_t>);
            nos->insert(lineNo);
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
    out << qr.word << " occurs " << qr.nos->size()
        << (qr.nos->size() > 1 ? " times" : " time") << endl;
    for (auto i : *qr.nos)
        out << "\t(line " << i + 1 << ") " << qr.input->at(i) << endl;
    return out;
}

void runQueries(ifstream& infile)
{
    TextQuery tq(infile);
    while (true) 
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") 
            break;
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