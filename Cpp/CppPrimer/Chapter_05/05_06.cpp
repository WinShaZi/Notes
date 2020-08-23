#include <iostream>

int main()
{
    int n;

    while (std::cin >> n)
        std::cout << n << " : " << 
            (n > 100 ? "Error" : (n >= 90 ? "A" : (n >= 80 ? "B" : (n >= 70 ? "C" : (n >= 60 ? "D" : "E"))))) 
            << std::endl;

    system("pause");
    return 0;
}