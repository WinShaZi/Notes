#include <iostream>
#include <thread>
#include <future>
#include <chrono>

int main(int argc, char const *argv[])
{
    // 创建一个异步线程，并复制与一个期望，期望可以移动禁止拷贝
    std::future<std::string> fu = std::async([] {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return std::string("Hello World!");
    });

    std::cout << "wait..." << std::endl;
    /**
     * fu.wait()        阻塞等待异步线程返回期望值
     * fu.wait_for()    在一段之间内阻塞等待异步线程返回期望值，未能等到则返回false
     * fu.wait_until()  在指定的之间点之前阻塞等待异步线程返回期望值，未能等到则返回false
     */
    fu.wait();

    // 检查该期望是否为共享状态
    if (fu.valid())
    {
        // 当首次调用get()后共享状态被释放，若多次调用get()则返回异常
        std::cout << "fu.get() : " << fu.get() << std::endl;
    }

    return 0;
}
