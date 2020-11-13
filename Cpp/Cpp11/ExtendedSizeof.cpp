#include <iostream>

class Test
{
public:
    int m_i;
};

int main(int argc, char const *argv[])
{
    /**
     * 可以对类的成员进行计算大小 
     * 输出
     * 4
     */
    std::cout << sizeof(Test::m_i) << std::endl;

    return 0;
}
