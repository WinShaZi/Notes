#include <iostream>
#include <string>
#include <regex>

/**
 * std::regex_search进行搜索，搜索到了即范围首个匹配处内容
 */

int main(int argc, char const *argv[])
{
    std::string sourceStr = R"(<cfg><email>qq163</email></cfg>)";
    std::regex reg(R"(<([\w]+)>([\w]+)</(\1)>)");
    std::smatch sm;

    // 1
    std::cout << std::regex_search(sourceStr, reg) << std::endl;

    if (std::regex_search(sourceStr, sm, reg))
    {
        /**
         * 输出匹配内容的组数
         * 4
         */
        std::cout << "Size : " << sm.size() << std::endl;

        /**
         * 输出匹配的每一组
         * 0 : <email>qq163</email>
         * 1 : email
         * 2 : qq163
         * 3 : email
         */
        for (size_t i = 0; i < sm.size(); i++)
        {
            std::cout << "sm.str(" << i << ") : " << sm.str(i) << std::endl;
        }

        /**
         * 匹配串的前面所有的字符 
         * <cfg>
         */
        std::cout << "sm.prefix().str() : " << sm.prefix().str() << std::endl;
        /**
         * 匹配串的后面的所有字符 
         * </cfg>
         */
        std::cout << "sm.suffix().str() : " << sm.suffix().str() << std::endl;
    }

    return 0;
}
