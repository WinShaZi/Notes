/*

class HasPtr 
{
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const std::string &s = string()) : ps(new string(s)), i(0){}

    HasPtr(const HasPtr &hp) : ps (new string(*hp.ps)), i (hp.i) {}
    HasPtr& operator= (const HasPtr &hp)
    {
        auto newp = new string(*hp.ps);
        delete ps;
        ps = newp;
        i = hp.i;

        return *this;
    }

    string& getPs()
    {
        return *ps;
    }

    ~HasPtr () { delete ps; }
private:
    string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap (lhs.ps, rhs.ps);
    swap (lhs.i, rhs.i);
    cout << "call the swap function." << endl;
}

*/