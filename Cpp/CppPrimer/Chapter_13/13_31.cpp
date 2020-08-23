#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr& operator=(HasPtr tmp)
    {
        this->swap(tmp);
        return *this;
    }
    ~HasPtr() { delete ps; }

    void swap(HasPtr& rhs)
    {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "call swap(HasPtr &rhs)" << std::endl;
    }

    void show() const { std::cout << *ps << std::endl; }
private:
    std::string* ps;
    int i;
};

void swap(HasPtr& lhs, HasPtr& rhs)
{
    lhs.swap(rhs);
}

bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
    return *lhs.ps < *rhs.ps;
}

int main()
{
	HasPtr hp1 ("hello");
    HasPtr hp2 ("world");
    HasPtr hp3 ("Anna");
    vector<HasPtr> hvec;
    hvec.push_back(hp1);
    hvec.push_back(hp2);
    hvec.push_back(hp3);

    sort(hvec.begin(), hvec.end());

	for (auto n : hvec)
		n.show();

	system("pause");
	return 0;
}