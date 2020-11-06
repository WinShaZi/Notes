#include <iostream>

class Test
{
private:
    static int m_value;
public:
    static void Show() {}
};

//  任何非引用类型均可称为联合
union Un
{
    int i;
    double d;
    Test t;
};

int main(int argc, char const *argv[])
{
    Un un;

    return 0;
}
