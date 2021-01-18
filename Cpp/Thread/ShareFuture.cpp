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

    // 返回共享期望fus，fus可以拷贝，此时fu的共享状态被释放，不可调用fu.get()
    std::shared_future<std::string> fus = fu.share();
    /**
     * fus.wait()       阻塞等待异步线程返回期望值
     * fus.wait_for()   在一段之间内阻塞等待异步线程返回期望值，未能等到则返回false
     * fus.wait_until() 在指定的之间点之前阻塞等待异步线程返回期望值，未能等到则返回false
     */
    fus.wait();

    // 检查该期望是否未共享状态
    if (fus.valid())
    {
        // 可以多次调用get()
        std::cout << "fus.get() : " << fus.get() << std::endl;
    }

    if (fus.valid())
    {
        std::cout << "fus.get() : " << fus.get() << std::endl;
    }

    return 0;
}
