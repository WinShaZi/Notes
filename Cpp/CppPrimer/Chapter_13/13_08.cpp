#include <iostream>

using namespace std;

class HasPtr
{
private:
    string *ps;
    int i;
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
    HasPtr & operator=(const HasPtr &h1)
    {
        string *p = new string(*h1.ps);
        delete ps;
        
        this->i = h1.i;
        this->ps = p;

        return *this;
    }
};