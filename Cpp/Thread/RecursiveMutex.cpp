#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex rMtx;
int value = 100;

void Foo()
{
    // 允许同一线程多次加锁或多次解锁，并不会引发异常
    rMtx.lock();
    if (value > 0)
    {
        std::cout << value << std::endl;
        value--;
        Foo();
    }

    rMtx.unlock();
}

int main(int argc, char const *argv[])
{
    std::thread t(Foo);

    t.join();

    return 0;
}
