/*

class HasPtr 
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0){}
    HasPtr(const HasPtr& hp) : ps (new std::string(*hp.ps)), i (hp.i) {}
    HasPtr& operator= (const HasPtr& hp)
    {
        auto newp = new std::string(*hp.ps);
        delete ps;
        ps = newp;
        i = hp.i;
        
        return *this;
    }

    string& getPs()
    {
        cout << ps << endl;
        return *ps;
    }

    ~HasPtr () { delete ps; }
private:
    std::string *ps;
    int i;
};

*/