#include <iostream>

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];

    for (size_t ix = 0; ix < array_size; ++ix)
        ia[ix] = ix;

    system("pause");
    return 0; 
}