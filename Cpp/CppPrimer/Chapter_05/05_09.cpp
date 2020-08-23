#include <iostream>

int main()
{
    int count = 0;
    char ch;
    std::string st = "aoeiuv";

    while (std::cin >> ch)
    {
        if (st.find(tolower(ch)) != std::string::npos)
            count++;
    }
    std::cout << count << std::endl;

    system("pause");
    return 0;
}