#include <iostream>
#include <vector>
#include <initializer_list>

std::vector<int> Func(std::initializer_list<int> li)
{
    // 允许返回列表
    return li;
}

int main(int argc, char const *argv[])
{
    // 允许使用列表初始化
    int i = {10};
    std::vector<int> vi = Func({1,2, 3});
    std::vector<double> vd = {1, 2, 3};

    // 允许使用列表初始化申请内存
    int *pi = new int{10};
    int *pArr = new int[3]{1, 2, 3};

    delete pi;
    delete[] pArr;

    return 0;
}
