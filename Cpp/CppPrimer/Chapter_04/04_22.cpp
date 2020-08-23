#include <iostream>
#include <string>
#include <vector>

int main()
{
    const std::vector<int> vi{ 81, 56, 72, 31, 99};

    for (auto n : vi)
    {
        std::cout << n << ' ';
        std::cout << ((n < 60) ? "fail" : ((n < 75) ? "low pass" : ((n < 90) ? "pass" : "high pass"))) << std::endl;
    }

    std::cout << std::endl;

    for (auto n : vi)
    {
        std::string st;

        if (n < 60)
            st = "fail";
        else if (n < 75)
            st = "low pass";
        else if (n < 90)
            st = "pass";
        else
            st = "high pass";
        std::cout << n << ' ' << st << std::endl;
    }

    system("pause");
    return 0;
}