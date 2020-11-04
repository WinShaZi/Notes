#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    std::string str = "Hello World!";
    std::string &lstr = str;
    std::string &&rstr = "Hello World!";
    // std::string &&rstr = str;   // error
    // std::string &&rstr = lstr;  // error

    // std::move语句可以将左值变为右值而避免拷贝构造
    // std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝
    std::vector<std::string> vstr;
    // str == ""
    vstr.push_back(std::move(str));

    return 0;
}
