#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    void pub_mem();
protected:
    int prot_mem();
private:
    char priv_mem();
};

struct Pub_Derv : public Base
{
    int f() { return prot_mem(); }
    void memfcn(Base &b) { b = *this; }
};

struct Pro_Derv : protected Base
{
    int f() { return prot_mem(); }
    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base
{
    int f1() { return prot_mem(); }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
    int use_base() {return prot_mem();}
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Pro : public Pro_Derv
{
 //   void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv
{
 //   void memfcn(Base &b) { b = *this; }
};

int main()
{
	Pub_Derv d1;
    Priv_Derv d2;
    Pro_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Pro dd2;
    Derived_from_Private dd3;

    Base *p = &d1;          // d1的类型是Pub_Derv，合法
                            // 如果是保护或私有继承，则派生类不能向基类转换
//  p = &d2;              // d2的类型是Priv_Derv,非法
//  p = &d3;              // d3的类型是Prot_Derv，非法
    p = &dd1;             // dd1的类型是Derived_from_Public，合法
//  p = &dd2;             // dd2的类型是Derived_from_Private，非法
//  p = &dd3;
	

	system("pause");
	return 0;
}