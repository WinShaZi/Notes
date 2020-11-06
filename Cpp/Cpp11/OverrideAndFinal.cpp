#include <iostream>

class Base
{
public:
    virtual void Show()
    {
        std::cout << "Base::Show()" << std::endl;
    }
    // 标识该函数不能被派生类重写
    virtual void Func() final
    {
        std::cout << "Base::Func() final" << std::endl;
    }
};

class Derive : public Base
{
public:
    // 标识该函数必须是重载基类的函数
    virtual void Show() override
    {
        std::cout << "Derive::Show()" << std::endl;
    }
};

// 标识该类不能被继承
class CannotInherit final
{
};

int main(int argc, char const *argv[])
{

    return 0;
}
