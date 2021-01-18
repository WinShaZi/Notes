#include <iostream>
#include <thread>
#include <future>
#include <chrono>

int main(int argc, char const *argv[])
{
    // pr不可以复制可以swap交换
    std::promise<std::string> pr;
    // 承诺返回期望
    std::future<std::string> fu = pr.get_future();

    std::thread t([&] {
        std::cout << "wait..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        /**
         * pr.set_value()                       设置结果为指定值
         * pr.set_value_at_thread_exit()        设置结果为指定值，同时仅在线程退出时分发提醒
         * pr.set_exception()                   设置结果为指示异常
         * pr.set_exception_at_thread_exit()    设置结果为指示异常，同时仅在线程退出时分发提醒
         */
        pr.set_value(std::string("Hello World!"));
    });

    if (fu.valid())
    {
        // 当fu调用get()时需等待pr设置值
        std::cout << fu.get() << std::endl;
    }

    if (t.joinable())
    {
        t.join();
    }

    return 0;
}
