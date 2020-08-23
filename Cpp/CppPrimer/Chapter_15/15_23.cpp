#include <iostream>

using namespace std;

class Base
{
public:
    virtual int fcn() { cout << "Base::fcn()" << endl; }
};

class D1 : public Base
{
public:
    int fcn(int);
    virtual int fcn() override{ cout << "d1::fcn()" << endl; }
    virtual void f2(){ cout << "d1::f2()" << endl; }
};

class D2 : public D1
{
public:
    int fcn(int);
    int fcn() override { cout << "d2::fcn()" << endl; }
    void f2() override { cout << "d2::f2()" << endl; }
};

int main()
{
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;

    bp1->fcn();     // 虚调用，运行时调用Base::fcn
    bp2->fcn();     // 虚调用，运行时调用D1::fcn
    bp3->fcn();     // 虚调用，运行时调用D2::fcn

    D1 *d1p = &d1obj; 
    D2 *d2p = &d2obj;   //    bp2->f2();  错误，Base中没有f2成员。
    d1p->f2();          // 虚调用，运行时调用D1::f2()
    d2p->f2();          // 虚调用，运行时调用D2::f2()

    system("pause");
    return 0;
}