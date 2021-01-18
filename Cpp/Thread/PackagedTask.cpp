#include <iostream>
#include <thread>
#include <future>
#include <chrono>

int main(int argc, char const *argv[])
{
    // pack不可复制只能移动，移动之后pack的共享状态被释放
    std::packaged_task<std::string()> pack([]() {
        std::cout << "wait..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return std::string("Hello World!");
    });
    std::future<std::string> fu = pack.get_future();

    // 检查pack是否具有共享状态
    if (pack.valid())
    {
        /**
         * operator()                   令共享状态就绪，并解除阻塞任何等待此操作的线程
         * make_ready_at_thread_exit    仅在当前线程退出，并销毁所有线程局域存储期对象后，才令共享状态就绪
         */
        pack();
        if (fu.valid())
        {
            std::cout << fu.get() << std::endl;
        }
    }

    // 重置状态，抛弃任何先前执行的存储结果
    pack.reset();
    if (pack.valid())
    {
        pack();
        if (fu.valid())
        {
            std::cout << fu.get() << std::endl;
        }
    }

    return 0;
}
