#include <iostream>
#include <string>
#include <regex>

int main(int argc, char const *argv[])
{
    std::string sourceStr = R"(+2020-10-01+)";
    std::regex reg1(R"([\d]+)");
    std::regex reg2(R"(([\d]+)-([\d]+)-([\d]+))");

    /**
     * 将所有匹配之处替换
     * +****-****-****+
     */
    std::cout << std::regex_replace(sourceStr, reg1, "****") << std::endl;

    /**
     * 分组替换
     * +2020-10-01 01-10-2020+
     */
    std::cout << std::regex_replace(sourceStr, reg2, "$& $3-$2-$1") << std::endl;

    return 0;
}
