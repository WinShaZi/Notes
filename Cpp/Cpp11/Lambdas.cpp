#include <iostream>
#include <exception>

int main(int argc, char const *argv[])
{
    /**
     * 按值传递的捕获的参数在lambdas内不可修改
     * [=]() {};    均按值传递
     * [&]() {};    均按引用传递
     * [value]() {};   value按值传递
     * [&value]() {};  value按引用传递
     * [=, &value]() {};    除了value其他均按值传递
     * [&, value]() {};     除了value其他均按引用传递
     */

    // 一般调用
    auto func = []() { std::cout << "func" << std::endl; };

    /**
     * 输出
     * func
     */
    func();

    // 直接调用返回值
    int i = []() { return 1024; }();
    // 指定返回类型
    int j = []() -> int { return 1024; }();

    // 异常
    try
    {
        []() { throw std::invalid_argument("invalid_argument"); }();
    }
    catch (const std::exception &e)
    {
        /**
         * 输出
         * invalid_argument
         */
        std::cout << e.what() << std::endl;
    }

    // 按值传递参数可变(仅在lambdas内部可改)
    int value = 0;
    [=]() mutable { value++; }();

    return 0;
}
