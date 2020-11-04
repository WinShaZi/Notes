#include <iostream>

struct Test
{
    void LeftFunc() &
    {
        std::cout << "LeftFunc" << std::endl;
    }
    void RightFunc() &&
    {
        std::cout << "RightFunc" << std::endl;
    }
};

int main()
{
    // 引用限定可以让成员函数只能被左值对象调用或者只能被右值对象调用，限定this指针指向的是左值还是右值
    // 成员函数参数列表后既有const又有引用限定符的话，引用限定符必须在const限定符后面

    Test t;
    t.LeftFunc();
    // t.RightFunc(); // error

    Test().RightFunc();
    // Test().LeftFunc(); // error

    return 0;
}
