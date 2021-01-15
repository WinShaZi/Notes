#include <iostream>
#include <thread>

int main(int argc, char const *argv[])
{
    auto func = [](const std::string &str, const int &num) {
        for (int i = 0; i < num; i++)
        {
            // 获取当前线程的ID
            std::cout << str << " " << std::this_thread::get_id() << std::endl;
        }
    };

    std::cout << "--------BEGIN--------" << std::endl;

    // 创建一个线程，执行函数并传入两个参数
    std::thread t_join(func, "join", 10);

    // 若该线程能够汇入主线程，则汇入主线程
    if (t_join.joinable())
    {
        // 主线程等该线程，t_join结束后才会结束
        t_join.join();
    }

    std::thread t_detach(func, "detach", 10);

    // 主线程不等待t_detach，主线程结束则结束
    t_detach.detach();

    std::cout << "---------END---------" << std::endl;

    return 0;
}
