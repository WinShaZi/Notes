#include <iostream>

using namespace std;

class Base
{
private:
    string basename;
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
};

class derived : public Base
{
private:
    int i;
public:
    void ptint(ostream &os) { Base::print(os); os << " " << i; }
};

int main()
{


    system("pause");
    return 0;
}