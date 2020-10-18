#include <iostream>
#include <string>
#include <regex>

/**
 * std::sregex_iterator进行搜索，可获取所有匹配项
 */

int main(int argc, char const *argv[])
{
    std::string sourceStr = R"(
        <cfg>
            <name>ShaZi</name>
            <email>qq163</email>
            <number>0123456789</number>
        </cfg>
    )";
    std::regex reg(R"(<([\w]+)>([\w]+)</(\1)>)");

    {
        std::sregex_iterator pos(sourceStr.begin(), sourceStr.end(), reg);
        std::sregex_iterator end;

        // 循环输出所有匹配项
        while (pos != end)
        {
            std::cout << pos->size() << std::endl;
            for (size_t i = 0; i < pos->size(); i++)
            {
                std::cout << pos->str(i) << std::endl;
            }

            pos++;
        }
    }

    {
        /**
         * 获取正则表达式中第2组匹配
         * -1 会获取与下一个匹配之前的字符
         */
        std::sregex_token_iterator pos(sourceStr.cbegin(), sourceStr.cend(), reg, 2);
        std::sregex_token_iterator end;

        /**
         * 循环输出所有匹配项 
         * ShaZi
         * qq163
         * 0123456789
         */
        while (pos != end)
        {
            std::cout << pos->str() << std::endl;

            pos++;
        }
    }

    return 0;
}
