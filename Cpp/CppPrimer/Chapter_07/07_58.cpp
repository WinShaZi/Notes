/*

// example.h

class Example
{
 public:
    static double rate = 6.5;       // 错误，静态成员类内初始化应该是一个const表达式
    // 改为 static constexpr double rete = 6.5;
    static const int vecSize = 20;
    static vector<double> vec(vecSize); // vector不需要在类内就定义大小
    // 改为static vector<double> vec；
}

// examplec.cpp

#include "example.h"

double Example::rate;
vector<double> Example::vec;

*/