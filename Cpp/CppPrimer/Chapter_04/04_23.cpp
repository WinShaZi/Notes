#include <iostream>
#include <string>

int main()
{
    std::string s = "word";
    std::string pl = s + ((s[s.size() - 1] == 's') ? "" : "s");

    std::cout << s << ' ' << pl << std::endl;

    system("pause");
    return 0;
}