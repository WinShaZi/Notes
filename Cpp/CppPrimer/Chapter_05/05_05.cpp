#include <iostream>

int main()
{
    int n;

    while (std::cin >> n)
    {
        char ch;
        
        if (n > 100)
            continue;
        else if (n >= 90)
            ch = 'A';
        else if (n >= 80)
            ch = 'B';
        else if (n >= 70)
            ch = 'C';
        else if (n >= 60)
            ch = 'D';
        else
            ch = 'E';
        std::cout << n << " : " << ch << std::endl;
    }

    system("pause");
    return 0;
}