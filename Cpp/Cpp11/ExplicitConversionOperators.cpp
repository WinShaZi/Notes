#include <iostream>
#include <string>

class Test
{
public:
    operator int()
    {
        return sizeof(*this);
    }

    // 静止隐式转换
    explicit operator const char*() 
    {
        return "Test";
    }
};

int main(int argc, char const *argv[])
{
    Test t;

    /**
     * 输出
     * 1
     * Test
     */
    std::cout << int(t) << std::endl;
    std::cout << (const char*)(t) << std::endl;
    // std::cout << std::string(t) << std::endl;   // error

    return 0;
}
