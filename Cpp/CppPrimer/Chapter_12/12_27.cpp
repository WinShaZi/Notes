/*

class QueryResult;
class TextQuery 
{
public:
    using LineNo = vector<string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> input;
    map<string, shared_ptr<set<LineNo>>> result;
};

class QueryResult 
{
    friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(const string& s, shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v)
        : word(s), nos(set), input(v) { }
private:
    string word;
    shared_ptr<std::set<TextQuery::LineNo>> nos;
    shared_ptr<vector<string>> input;
};

*/