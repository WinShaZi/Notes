#ifndef TEST_H_
#define TEST_H_

#include <iostream>

template <typename T>
void Func(T t)
{
    std::cout << t << std::endl;
}

void A();
void B();

#endif  // TEST_H_