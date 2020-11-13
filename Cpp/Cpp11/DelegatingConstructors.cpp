#include <iostream>
#include <string>

class Test
{
private:
    int m_i;
    double m_d;
    std::string m_str;

public:
    // 将构造函数委托到其他构造函数，已经委托的构造函数不能允许其他初始化序列
    Test(int i, double d, std::string str) : m_i(i), m_d(d), m_str(str) { std::cout << 3 << std::endl; }
    Test(int i, double d) : Test(i, d, "") { std::cout << 2 << std::endl; }
    Test(int i) : Test(i, 0) { std::cout << 1 << std::endl; }
    Test() : Test(0) { std::cout << 0 << std::endl; }
};

int main(int argc, char const *argv[])
{
    /**
     * 输出
     * 3
     * 2
     * 1
     * 0
     */
    Test t;

    return 0;
}
