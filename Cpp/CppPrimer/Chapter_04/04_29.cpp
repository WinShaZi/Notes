#include <iostream>

int main()
{
    int x[10];
    int *p = x;

    std::cout << sizeof(x) / sizeof(*x) << std::endl; //arrar size /  int size
    std::cout << sizeof(p) / sizeof(*p) << std::endl; //pointer size / int size

    system("pause");
    return 0;
}