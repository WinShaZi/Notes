#include <iostream>

class A
{
public:
    int m_i;

    A() : m_i(0) {}
    A(const int &i) : m_i(i) {}
};

class B : public A
{
    // 集成构造函数
    using A::A;
};

int main(int argc, char const *argv[])
{
    B b1;
    B b2(10);

    /**
     * 输出
     * 0 10
     */
    std::cout << b1.m_i << " " << b2.m_i << std::endl;

    return 0;
}
