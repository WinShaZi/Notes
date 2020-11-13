#include <iostream>

class Test
{
public:
    Test() = default;   // 默认使用默认构造函数，此处已经定义不可外部再定义
    Test(const Test &test) = delete; // 禁止拷贝构造函数
};

// Test::Test() {} // error

int main(int argc, char const *argv[])
{
    Test t1;
    // Test t2 = t1;   // error

    return 0;
}
