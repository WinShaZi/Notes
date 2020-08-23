#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <new>
#include <algorithm>
#include <typeinfo>

using namespace std;

class A
{
public:
	virtual ~A() {}
};

class B : public A { };

class C : public B { };

class D : public B, public A { };

int main()
{
	A *pa1 = new C;

    if(C *qc = dynamic_cast<C*>(pa1))
    {
        cout << "success" << endl;
    }
    else
    {
        cout << "fail" << endl;
    }

	A *pa2 = new C;
	try
    {
		const C &rc = dynamic_cast<const C&>(*pa2);
	}
    catch(bad_cast &e){
		cout << e.what() << endl;
	}

	C c = C();
    
	if(typeid(*pa1) == typeid(*pa2)) 
        cout << "same type" << endl;
	if(typeid(*pa1) == typeid(c)) 
        cout << "same type as C" << endl;
	if(typeid(*pa1) == typeid(C)) 
        cout << "same type as C" << endl;

    system("pause");  
    return 0;  
}