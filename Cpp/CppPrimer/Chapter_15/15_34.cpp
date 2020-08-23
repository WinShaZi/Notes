/*

(a)： 

1: Query::Query(const std::string& s) 
2: WordQuery::WordQuery(const std::string& s) 
3: AndQuery::AndQuery(const Query& left, const Query& right);
4: BinaryQuery(const Query&l, const Query& r, std::string s);
5: Query::Query(std::shared_ptr<Query_base> query) 2times
6: OrQuery::OrQuery(const Query& left, const Query& right);
7: BinaryQuery(const Query&l, const Query& r, std::string s);
8: Query::Query(std::shared_ptr<Query_base> query) 2times

(b)：运算符"<<"会调用Query的rep成员，Query.rep()调用的是OrQuery的rep(因为初始化对象q时使用的是值是"|"运算符返回的Query，
    而该对象的智能指针q指向的是一个OrQuery对象)，而OrQuery并没有定义rep成员，所以直接使用直接基类BinaryQuery的rep成员

(c)：q调用的是OrQuery的eval函数，因为是虚函数，且使用引用调用，需动态绑定

*/