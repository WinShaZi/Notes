#include <iostream>
#include <string>
#include <regex>

/**
 * std::regex_match会进行全词匹配而不是部分匹配
 */

int main(int argc, char const *argv[])
{
    std::string sourceStr = R"(<email>number123</email>)";

    std::regex reg1(R"([\w]+)");                   // 欲图匹配中间的单词和数字
    std::regex reg2(R"(<([\w]+)>([\w]+)</(\1)>)"); // 全词匹配

    // 0
    std::cout << std::regex_match(sourceStr, reg1) << std::endl;

    // 1
    std::cout << std::regex_match(sourceStr, reg2) << std::endl;

    // 1
    std::cout << std::regex_match(sourceStr.begin(), sourceStr.end(), reg2) << std::endl;

    return 0;
}
