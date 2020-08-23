#include <iostream>

int main()
{
    int count_vowal = 0;
    int count_symbol = 0;
    char ch;
    const std::string st1 = "aoeiuv";
    const std::string st2 = " \n\r\t\v\f";

    while (std::cin.get(ch))
    {
        if (st1.find(tolower(ch)) != std::string::npos)
            count_vowal++;
        else if (st2.find(ch) != std::string::npos)
            count_symbol++;
    }
    std::cout << "Vowal : " << count_vowal << std::endl;
    std::cout << "Tabulate : " << count_symbol << std::endl;

    system("pause");
    return 0;
}