#include <iostream>
#include <atomic>

int main(int argc, char const *argv[])
{
    std::atomic_int ai;
    int valueOne = 1;
    int valueTwo = 2;

    // 检查原子对象是否免锁
    std::cout << "ai.is_free_lock() : " << ai.is_lock_free() << std::endl;
    // 原子地以非原子对象替换原子对象的值
    ai.store(0);
    // 原子地获得原子对象的值
    std::cout << "ai.load()         : " << ai.load() << std::endl;
    std::cout << "ai.exchange()     : " << ai.exchange(1) << std::endl;
    std::cout << "ai                : " << ai << std::endl;

    std::cout << ai << " " << valueOne << " " << valueTwo << std::endl;
    /**
     * weak版本的CAS允许出现错误的返回，通常它比起strong有更高的性能
     * 无锁的原子操作，读-改-写
     * 当ai的值与valueOne的值相等时，ai的值被赋值为valueTwo，返回true
     * 当ai的值与valueOne不相等时，valueOne的值被赋值为ai，返回false
     */
    std::cout << ai.compare_exchange_strong(valueOne, valueTwo) << std::endl;
    std::cout << ai << " " << valueOne << " " << valueTwo << std::endl;
    std::cout << ai.compare_exchange_strong(valueOne, valueTwo) << std::endl;
    std::cout << ai << " " << valueOne << " " << valueTwo << std::endl;

    return 0;
}
