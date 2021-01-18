#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

int main(int argc, char const *argv[])
{
    /**
     * std::chrono::system_clock    可以修改的系统时间
     * std::chrono::steady_clock    绝不修改的单调时间
     */
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock().now();
    // 睡眠500s毫秒
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock().now();

    // 获取相差的时间范围，int64_t表示64位整数类型，每份时间单位为std::nano
    std::chrono::duration<int64_t, std::nano> spendTime = endTime - startTime;
    // 获取该事件范围内的事件片段数量，即有多少std::nano
    std::cout << "count : " << spendTime.count() << std::endl;
    // std::nano的最大值
    std::cout << "max   : " << spendTime.max().count() << std::endl;
    // std::nano的最小值
    std::cout << "min   : " << spendTime.min().count() << std::endl;

    // 最短时间周期的时钟
    std::chrono::high_resolution_clock::time_point nowTime = std::chrono::high_resolution_clock::now();
    // 与C时间相互转换
    time_t timeT = std::chrono::high_resolution_clock::to_time_t(nowTime);
    nowTime = std::chrono::high_resolution_clock::from_time_t(timeT);
    std::cout << "time  : " << timeT << std::endl;

    return 0;
}
