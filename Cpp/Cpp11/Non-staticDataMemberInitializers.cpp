#include <iostream>

class Test
{
public:
    static const int sc_i = 1;
    // static int s_i = 2;     // error
    static int s_i;
    const int c_i = 3;
    int i = 4;

public:
    Test() : c_i(3) {}
};

int Test::s_i = 2;

int main()
{
    Test t;

    std::cout << t.sc_i << " " << t.s_i << " " << t.c_i << " " << t.i << std::endl;

    return 0;
}
