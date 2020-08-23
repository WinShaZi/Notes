#include <iostream>
#include <vector>

int main()
{
    std::string st("hello world");
    char ch[] = "hello world";
    int i = 1;
    double d = 2.5;
    const std::string *ps = &st;
    char *pc = ch;
    void *pv = nullptr;

    pv = static_cast<void *>(const_cast<std::string *>(ps));
    std::cout << pv << std::endl;

    i = static_cast<int>(*pc);
    std::cout << i << std::endl;

    static_cast<double *>(pv);
    pv = &d;
    std::cout << pv << std::endl; 

    pc = static_cast<char *>(pv);
    std::cout << *pc << std::endl;

    system("pause");
    return 0;
}