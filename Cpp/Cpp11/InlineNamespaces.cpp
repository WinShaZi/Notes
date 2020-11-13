#include <iostream>

namespace Letter
{
    inline namespace NA
    {
        class CA
        {
        };
    } // namespace NA

    namespace NB
    {
        class CB
        {
        public:
            // 同级命名空间中可以直接访问
            class CA m_ca;
        };
    } // namespace NB
} // namespace Letter

int main(int argc, char const *argv[])
{
    // Letter可以直接访问CA
    Letter::CA ca;
    Letter::NB::CB cb;

    return 0;
}
