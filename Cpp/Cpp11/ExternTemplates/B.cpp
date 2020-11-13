#include "Test.h"

// 标识该模板的int特例已经在其他地方实例化了，避免实例化冗余
extern template void Func<int>(int);

void B()
{
    Func<int>(996);
}
