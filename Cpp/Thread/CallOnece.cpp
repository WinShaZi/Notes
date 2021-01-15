#include <iostream>
#include <thread>
#include <mutex>

std::once_flag oneFlag;

void foo()
{
    std::cout << "foo" << std::endl;
}

void bar()
{
    // 在任何情况下foo只会调用一次
    std::call_once(oneFlag, foo);
}

int main(int argc, char const *argv[])
{
    std::thread t1(bar);
    std::thread t2(bar);
    std::thread t3(bar);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
