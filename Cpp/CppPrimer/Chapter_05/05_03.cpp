#include <iostream>

int main()
{
    int val = 1, sum = 0;

    while (val <= 10)
        sum += val, ++val;
    
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

    system("pause");
    return 0;
}